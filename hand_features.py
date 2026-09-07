class HandFeatures:
    WRIST = 0

    THUMB_TIP = 4
    INDEX_TIP = 8
    MIDDLE_TIP = 12
    RING_TIP = 16
    PINKY_TIP = 20

    def __init__(self, landmarks):
        self.landmarks = landmarks

    def wrist(self):
        return self.landmarks[self.WRIST]

    def index_tip(self):
        return self.landmarks[self.INDEX_TIP]

    def middle_tip(self):
        return self.landmarks[self.MIDDLE_TIP]

    def ring_tip(self):
        return self.landmarks[self.RING_TIP]

    def pinky_tip(self):
        return self.landmarks[self.PINKY_TIP]

    def thumb_tip(self):
        return self.landmarks[self.THUMB_TIP]
