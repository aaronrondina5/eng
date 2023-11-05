from abc import ABC, abstractmethod


class Algorithm(ABC):
    @abstractmethod
    def execute(self, **kwargs):
        pass


class AlgorithmDecorator(Algorithm):
    def __init__(self, algorithm):
        self._algorithm = algorithm

    def algorithm(self):
        return self._algorithm
    
    def execute(self, **kwargs):
        return self._algorithm.execute()
