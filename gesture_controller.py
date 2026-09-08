import cv2

from hand_tracker import HandTracker
from hand_features import HandFeatures
from smoothing import ExponentialSmoother
from state_machine import MovementStateMachine
from udp.udp_sender import UDPsender


# -----------------------------
# Configuration
# -----------------------------

CAMERA_INDEX = 0

SMOOTHING_ALPHA = 0.2

DEAD_ZONE_MIN = 0.40
DEAD_ZONE_MAX = 0.60

STATE_REQUIRED_FRAMES = 5


# -----------------------------
# Initialization
# -----------------------------

camera = cv2.VideoCapture(CAMERA_INDEX)

if not camera.isOpened():
    raise RuntimeError("Could not open camera")


tracker = HandTracker()

x_smoother = ExponentialSmoother(
    alpha=SMOOTHING_ALPHA
)

y_smoother = ExponentialSmoother(
    alpha=SMOOTHING_ALPHA
)

state_machine = MovementStateMachine(
    required_frames=STATE_REQUIRED_FRAMES
)


# -----------------------------
# Gesture detection
# -----------------------------

def detect_command(x, y):
    """
    Convert hand position into a movement command.
    """
    send_to_server = UDPsender(5000, "127.0.0.1")
    # Center = STOP
    if DEAD_ZONE_MIN <= x <= DEAD_ZONE_MAX and \
       DEAD_ZONE_MIN <= y <= DEAD_ZONE_MAX:
        return "STOP"

    # Horizontal movement
    if x < DEAD_ZONE_MIN:
        send_to_server.send("LEFT")
        return "LEFT"

    if x > DEAD_ZONE_MAX:
        send_to_server.send("RIGHT")
        return "RIGHT"

    # Vertical movement
    if y < DEAD_ZONE_MIN:
        send_to_server.send("FORWARD")
        return "FORWARD"

    if y > DEAD_ZONE_MAX:
        send_to_server.send("BACKWARD")
        return "BACKWARD"

    return "STOP"


# -----------------------------
# Main loop
# -----------------------------

while True:

    ret, frame = camera.read()

    if not ret:
        print("Could not read frame")
        break

    result = tracker.detect(frame)

    command = "STOP"

    if result.hand_landmarks:

        landmarks = result.hand_landmarks[0]

        features = HandFeatures(landmarks)

        index_tip = features.index_tip()

        # Raw coordinates
        raw_x = index_tip.x
        raw_y = index_tip.y

        # Smoothed coordinates
        smooth_x = x_smoother.update(raw_x)
        smooth_y = y_smoother.update(raw_y)

        # Convert position to command
        command = detect_command(
            smooth_x,
            smooth_y
        )

        # Update state machine
        state = state_machine.update(command)

        # Draw index fingertip
        h, w, _ = frame.shape

        px = int(smooth_x * w)
        py = int(smooth_y * h)

        cv2.circle(
            frame,
            (px, py),
            10,
            (0, 255, 0),
            -1
        )

        # Display coordinates
        cv2.putText(
            frame,
            f"X: {smooth_x:.2f}",
            (20, 40),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.7,
            (255, 255, 255),
            2
        )

        cv2.putText(
            frame,
            f"Y: {smooth_y:.2f}",
            (20, 70),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.7,
            (255, 255, 255),
            2
        )

    else:

        # No hand detected
        x_smoother.reset()
        y_smoother.reset()

        state = state_machine.update("STOP")

    # Display state
    cv2.putText(
        frame,
        f"STATE: {state.value}",
        (20, 110),
        cv2.FONT_HERSHEY_SIMPLEX,
        0.8,
        (0, 255, 0),
        2
    )

    cv2.imshow(
        "CubVision Gesture Controller",
        frame
    )

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break


# -----------------------------
# Cleanup
# -----------------------------

camera.release()
cv2.destroyAllWindows()