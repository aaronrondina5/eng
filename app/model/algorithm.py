from abc import ABC


class Algorithm(ABC):
    def __init__(self, name):
        self._name = name

    def name(self):
        return self._name

    def brute_force(self, **kwargs):
        pass

    def decent(self, **kwargs):
        pass

    def optimal(self, **kwargs):
        pass
