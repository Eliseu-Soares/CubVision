import cv2

from hand_tracker import HandTracker


camera = cv2.VideoCapture(0)

if not camera.isOpened():
    raise RuntimeError("Could not open camera")


tracker = HandTracker()

HAND_CONNECTIONS = [
    (0, 1),
    (1, 2),
    (2, 3),
    (3, 4),

    (0, 5),
    (5, 6),
    (6, 7),
    (7, 8),

    (5, 9),
    (9, 10),
    (10, 11),
    (11, 12),

    (9, 13),
    (13, 14),
    (14, 15),
    (15, 16),

    (13, 17),
    (17, 18),
    (18, 19),
    (19, 20),

    (0, 17),
]

while True:
    ret, frame = camera.read()

    if not ret:
        print("Could not read frame")
        break

    result = tracker.detect(frame)

    # Verifica se alguma mão foi detectada
    if result.hand_landmarks:

        hand_landmarks = result.hand_landmarks[0]
        from hand_features import HandFeatures
        features = HandFeatures(hand_landmarks)

        index = features.index_tip()

        print(
            f"Index: "
            f"x={index.x:.3f}, "
            f"y={index.y:.3f}, "
            f"z={index.z:.3f}"
)

        h, w, _ = frame.shape

        points = []

        # Converter coordenadas normalizadas
        # para coordenadas da imagem
        for landmark in hand_landmarks:

            x = int(landmark.x * w)
            y = int(landmark.y * h)

            points.append((x, y))

            cv2.circle(
                frame,
                (x, y),
                5,
                (0, 255, 0),
                -1
            )

        # Desenhar conexões
        for start, end in HAND_CONNECTIONS:

            cv2.line(
                frame,
                points[start],
                points[end],
                (255, 0, 0),
                2
            )
        
    cv2.imshow("Hand Tracker", frame)

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break


camera.release()
cv2.destroyAllWindows()
