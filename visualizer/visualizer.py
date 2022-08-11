#!/usr/bin/env python3

import sys
import pygame
from time import sleep
from argparse import ArgumentParser

class Visualizer:

    SCREEN_WIDTH = 800
    SCREEN_HEIGHT = 600
    PADDING = 20
    MAX_FPS = 60
    FONT_SIZE = 20
    BG_COLOR = (80, 43, 58)
    TEXT_COLOR = (249, 226, 125)
    EDGE_COLOR = (255, 141, 109)
    NODE_COLOR = (255, 88, 93)
    ANT_COLOR = (255, 198, 88)
    ANT_RADIUS = 5
    NODE_RADIUS = 8

    def __init__(self):
        self.ants = 0
        self.max_x = 0
        self.max_y = 0
        self.min_x = sys.maxsize
        self.min_y = sys.maxsize
        self.nodes = []
        self.positions = {}
        self.edges = []
        self.turns = []
        self.turn = 0
        self.screen = pygame.display.set_mode((self.SCREEN_WIDTH, self.SCREEN_HEIGHT))
        pygame.display.set_caption("Lem-in Visualizer")

    def ajdust_node_positions(self):
        scale = min(
            ((self.SCREEN_WIDTH - 2 * self.PADDING) / self.max_x),
            ((self.SCREEN_HEIGHT - 2 * self.PADDING) / self.max_y)
        )
        # left_margin = (self.max_x - self.min_x) / 2
        for node in self.nodes:
            self.positions[node] = (
                self.PADDING + self.positions[node][0] * scale,
                self.PADDING + self.positions[node][1] * scale
            )

    def render(self):
        self.render_graph()
        self.render_ants()

    def render_graph(self):
        self.screen.fill(self.BG_COLOR)
        for edge in self.edges:
            pygame.draw.aaline(self.screen, self.EDGE_COLOR, tuple(self.positions[edge[0]]), tuple(self.positions[edge[1]]))
        for node in self.nodes:
            pygame.draw.circle(self.screen, self.NODE_COLOR, tuple(self.positions[node]), self.NODE_RADIUS)

    def render_ants(self):
        if self.turn >= len(self.turns):
            return 
        for move in self.turns[self.turn]:
            pygame.draw.circle(self.screen, self.ANT_COLOR, tuple(self.positions[move]), self.ANT_RADIUS)
        self.turn += 1

    def read_input(self):
        self.ants = int(sys.stdin.readline().strip('\n'))
        
        while True:
            line = sys.stdin.readline().strip('\n')
            if line[0] == '#':
                continue
            if not ' ' in line:
                break
            split = line.split(' ')
            x = int(split[1])
            y = int(split[2])
            self.max_x = max(self.max_x, x)
            self.max_y = max(self.max_y, y)
            self.min_x = min(self.min_x, x)
            self.min_y = min(self.min_y, y)
            node = split[0]
            self.nodes.append(node)
            self.positions[node] = (x, y)

        if not line[0] == '#':
            self.edges.append(line.split('-'))

        while True:
            line = sys.stdin.readline().strip('\n')
            if len(line) == 0:
                break
            if line[0] == '#':
                continue
            if not '-' in line:
                break
            self.edges.append(line.split('-'))

        while True:
            line = sys.stdin.readline().strip('\n')
            if len(line) == 0:
                break
            splits = line.split(' ')
            self.turns.append(list(split.split('-')[1] for split in splits[:-1])) #! Remove [:-1] when our printer is fixed
            
def main():
    argparser = ArgumentParser(description="Visualizes your Lem-in.")

    argparser.add_argument("-a", action = "store_true")
    args = argparser.parse_args()

    visualizer = Visualizer()
    visualizer.read_input()
    visualizer.ajdust_node_positions()

    running = True
    while running:
        visualizer.render()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False

        pygame.display.flip()
        sleep(1)

    pygame.quit()

if __name__ == "__main__":
    main()
