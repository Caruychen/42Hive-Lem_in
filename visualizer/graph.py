import sys

class Graph:

    def __init__(self):
        self.nodes = []
        self.positions = {}
        self.edges = []
        self.start = ""
        self.max_x = 0
        self.max_y = 0
        self.min_x = sys.maxsize
        self.min_y = sys.maxsize
        self.ant_count = 0

    def set_extreme_values(self):
        self.max_x = 0
        self.max_y = 0
        self.min_x = sys.maxsize
        self.min_y = sys.maxsize
        for node in self.nodes:
            x, y = self.positions[node]
            self.max_x = max(self.max_x, x)
            self.max_y = max(self.max_y, y)
            self.min_x = min(self.min_x, x)
            self.min_y = min(self.min_y, y)
        print(self.positions)
        print(self.min_x, self.max_x, self.min_y, self.max_y)

    def zoom(self, pos, direction):
        factor = 1.1
        if direction == -1:
            factor = 0.9
        for node in self.nodes:
            vec = pos - self.positions[node]
            self.positions[node] = pos - (vec * factor)

    
