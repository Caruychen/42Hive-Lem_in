import sys

class Graph:

    def __init__(self):
        self.nodes = []
        self.positions = {}
        self.edges = []
        self.start = ""
        self.end = ""
        self.max_x = 0
        self.max_y = 0
        self.min_x = sys.maxsize
        self.min_y = sys.maxsize
        self.ant_count = 0
        self.paths = []

    def zoom(self, pos, direction):
        factor = 1.1
        if direction == -1:
            factor = 0.9
        for node in self.nodes:
            vec = pos - self.positions[node]
            self.positions[node] = pos - (vec * factor)
