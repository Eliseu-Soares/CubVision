from enum import Enum


class MovementState(Enum):
    STOP = "STOP"
    LEFT = "LEFT"
    RIGHT = "RIGHT"
    FORWARD = "FORWARD"
    BACKWARD = "BACKWARD"


class MovementStateMachine:
    def __init__(self, required_frames=5):
        self.state = MovementState.STOP

        self.pending_state = MovementState.STOP
        self.pending_frames = 0

        self.required_frames = required_frames

    def update(self, command):

        new_state = MovementState(command)

        # Já estamos nesse estado
        if new_state == self.state:
            self.pending_state = new_state
            self.pending_frames = 0
            return self.state

        # Novo candidato
        if new_state != self.pending_state:
            self.pending_state = new_state
            self.pending_frames = 1
        else:
            self.pending_frames += 1

        # Confirma mudança
        if self.pending_frames >= self.required_frames:
            self.state = self.pending_state
            self.pending_frames = 0

        return self.state

    def get_state(self):
        return self.state
