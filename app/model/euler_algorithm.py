from app.model.algorithm import AlgorithmDecorator


class EulerAlgorithm(AlgorithmDecorator):
    def __init__(self, euler_id, algorithm):
        super().__init__(algorithm)
        self._euler_id = euler_id

    def euler_id(self):
        return self._euler_id
