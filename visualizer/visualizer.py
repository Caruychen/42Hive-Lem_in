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
    PATH_COLOR = (12, 188, 210)
    EDGE_COLOR = (80, 100, 118)
    START_NODE_COLOR = (88, 255, 104)
    END_NODE_COLOR = (209, 75, 209)
    NODE_COLOR = (249, 56, 34)
    ANT_COLOR = (255, 152, 0)
    ANT_RADIUS = 8
    NODE_RADIUS = 5
    TEMPERATURE_FACTOR = 0.99

    def __init__(self):
        self.graph = Graph()

        self.turns = []
        self.turn = 0
        self.start_of_turn = True

        self.ideal_length = 15
        self.temperature = 150
        self.iters = 0
        self.max_iters = 1000

        info = pygame.display.Info()
        self.SCREEN_WIDTH = info.current_w
        self.SCREEN_HEIGHT = info.current_h
        self.resolution = (self.SCREEN_WIDTH, self.SCREEN_HEIGHT)
        self.screen = pygame.display.set_mode(self.resolution, FULLSCREEN | DOUBLEBUF, 16)
        self.font = pygame.font.SysFont("menlo", self.FONT_SIZE, bold = True)
        self.center = Vector2(self.SCREEN_WIDTH / 2, self.SCREEN_HEIGHT / 2)

        self.text_auto_layout = self.font.render("auto-layout in progress. press space to stop.", False, self.TEXT_COLOR)
        self.text_solution = self.font.render("press space to replay solution.", False, self.TEXT_COLOR)

        pygame.display.set_caption("Lem-in Visualizer")

    def set_random_xy(self):
        for node in self.graph.nodes:
            self.graph.positions[node] = Vector2(randint(0, self.SCREEN_WIDTH), randint(0, self.SCREEN_HEIGHT))

    def adjust_node_positions(self):
        scale = 1
        if self.graph.max_x != 0 and self.graph.max_y != 0:
            scale = min(
                ((self.SCREEN_WIDTH - 2 * self.PADDING) / self.graph.max_x),
                ((self.SCREEN_HEIGHT - 2 * self.PADDING) / self.graph.max_y)
            )
        for node in self.graph.nodes:
            self.graph.positions[node] = Vector2(
                int(self.PADDING + self.graph.positions[node][0] * scale),
                int(self.PADDING + self.graph.positions[node][1] * scale)
            )

    def render_bg(self):
        self.screen.fill(self.BG_COLOR)

    def render_edges(self):
        for edge in self.graph.edges:
            pygame.draw.aaline(self.screen, self.EDGE_COLOR, self.graph.positions[edge[0]], self.graph.positions[edge[1]])

    def render_nodes(self):
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

    def render_paths(self):
        for edge in self.graph.paths:
            pygame.draw.aaline(self.screen, self.PATH_COLOR, self.graph.positions[edge[0]], self.graph.positions[edge[1]])

    def render_text(self, text):
        self.screen.blit(text, Vector2(self.PADDING, self.PADDING))
