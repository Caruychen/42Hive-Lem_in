from graph import Graph
import pygame
from pygame import DOUBLEBUF, FULLSCREEN, Vector2
from random import randint

class Visualizer:

    PADDING = 20
    MAX_FPS = 60
    FONT_SIZE = 12
    BG_COLOR = (32, 42, 68)
    TEXT_COLOR = (255, 255, 255)
    EDGE_COLOR = (2, 138, 155)
    START_NODE_COLOR = (88, 179, 104)
    END_NODE_COLOR = (199, 65, 123)
    NODE_COLOR = (249, 56, 34)
    ANT_COLOR = (255, 152, 0)
    ANT_RADIUS = 6
    NODE_RADIUS = 3
    TEMPERATURE_FACTOR = 0.99

    def __init__(self):
        self.graph = Graph()

        self.turns = []
        self.turn = 0
        self.start_of_turn = True

        self.ideal_length = 15
        self.repulsion_constant = 3.0
        self.attraction_constant = 0.5
        self.temperature = 150
        self.iters = 0
        self.max_iters = 200

        info = pygame.display.Info()
        self.SCREEN_WIDTH = info.current_w
        self.SCREEN_HEIGHT = info.current_h
        self.resolution = (self.SCREEN_WIDTH, self.SCREEN_HEIGHT)
        self.screen = pygame.display.set_mode(self.resolution, FULLSCREEN | DOUBLEBUF, 16)
        self.font = pygame.font.SysFont("menlo", self.FONT_SIZE, bold = True)
        self.center = Vector2(self.SCREEN_WIDTH / 2, self.SCREEN_HEIGHT / 2)

        pygame.display.set_caption("Lem-in Visualizer")

    def set_random_xy(self):
        for node in self.graph.nodes:
            self.graph.positions[node] = Vector2(randint(0, self.SCREEN_WIDTH), randint(0, self.SCREEN_HEIGHT))

    def adjust_node_positions(self):
        scale = min(
            ((self.SCREEN_WIDTH - 2 * self.PADDING) / self.graph.max_x),
            ((self.SCREEN_HEIGHT - 2 * self.PADDING) / self.graph.max_y)
        )
        for node in self.graph.nodes:
            self.graph.positions[node] = Vector2(
                int(self.PADDING + self.graph.positions[node][0] * scale),
                int(self.PADDING + self.graph.positions[node][1] * scale)
            )

    def render_graph(self):
        self.screen.fill(self.BG_COLOR)
        for edge in self.graph.edges:
            pygame.draw.aaline(self.screen, self.EDGE_COLOR, self.graph.positions[edge[0]], self.graph.positions[edge[1]])
        for node in self.graph.nodes:
            pygame.draw.circle(self.screen, self.NODE_COLOR, self.graph.positions[node], self.NODE_RADIUS)
        pygame.draw.circle(self.screen, self.START_NODE_COLOR, self.graph.positions[self.graph.start], self.ANT_RADIUS)
        pygame.draw.circle(self.screen, self.END_NODE_COLOR, self.graph.positions[self.graph.end], self.ANT_RADIUS)

    def render_ants(self):
        if self.turn >= len(self.turns):
            return 
        for move in self.turns[self.turn]:
            pygame.draw.circle(self.screen, self.ANT_COLOR, self.graph.positions[move], self.ANT_RADIUS)
        self.turn += 1

    def render_text(self, text):
        text = self.font.render(text, False, self.TEXT_COLOR)
        self.screen.blit(text, Vector2(self.PADDING, self.PADDING))
        pass
