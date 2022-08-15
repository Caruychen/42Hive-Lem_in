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
