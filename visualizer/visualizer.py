#!/usr/bin/env python3

import sys
import pygame
from pygame import Vector2
from random import randint
from math import log
# from pygame import gfxdraw
from argparse import ArgumentParser

class Visualizer:

    SCREEN_WIDTH = 800
    SCREEN_HEIGHT = 600
    PADDING = 20
    MAX_FPS = 60
    FONT_SIZE = 20
    BG_COLOR = (32, 42, 68)
    TEXT_COLOR = (255, 255, 255)
    EDGE_COLOR = (2, 138, 155)
    NODE_COLOR = (249, 56, 34)
    ANT_COLOR = (255, 152, 0)
    ANT_RADIUS = 8
    NODE_RADIUS = 3
    TEMPERATURE_FACTOR = 0.98

    def __init__(self):
        self.graph = Graph()
        self.max_x = 0
        self.max_y = 0
        self.min_x = sys.maxsize
        self.min_y = sys.maxsize
        self.ant_count = 0
        self.ants = []
        self.nodes = []
        self.positions = {}
        self.edges = []
        self.start = ""
        self.turns = []
        self.turn = 0
        self.start_of_turn = True

        self.ideal_length = 10
        self.repulsion_constant = 2.0
        self.attraction_constant = 1.0
        self.temperature = 50
        self.iters = 0
        self.max_iters = 1000
        self.center = Vector2(self.SCREEN_WIDTH / 2, self.SCREEN_HEIGHT / 2)

        self.screen = pygame.display.set_mode((self.SCREEN_WIDTH, self.SCREEN_HEIGHT))
        pygame.display.set_caption("Lem-in Visualizer")

    def set_random_xy(self):
        for node in self.nodes:
            self.positions[node] = Vector2(randint(0, self.SCREEN_WIDTH), randint(0, self.SCREEN_HEIGHT))

    def fruchterman_reingold(self):
        """
        Implementation of Fructherman and Reingold's force-directed graph drawing algorithm.
        """
        offset = {}
        for node in self.nodes:
            offset[node] = Vector2(0, 0)

        # Repulsion
        for node_a in self.nodes:
            for node_b in self.nodes:
                if node_a == node_b:
                    continue
                vec = self.positions[node_b] - self.positions[node_a]
                if vec.length() != 0:
                    offset[node_a] += ((self.ideal_length ** 2) / vec.length()) * vec.normalize()

        # Attraction
        for edge in self.edges:
            node_a = edge[0]
            node_b = edge[1]
            vec = self.positions[node_b] - self.positions[node_a]
            if vec.length() != 0:
                v = ((vec.length() ** 2) / self.ideal_length) * vec.normalize()
                offset[node_a] += v
                offset[node_b] -= v

        # Apply net force
        for node in self.nodes:
            if offset[node].magnitude() > self.temperature:
                offset[node] = offset[node].normalize()
                offset[node] *= self.temperature

            self.positions[node] += offset[node]

            if self.positions[node].x >= self.SCREEN_WIDTH:
                self.positions[node].x = self.SCREEN_WIDTH
            if self.positions[node].x < 0:
                self.positions[node].x = 0
            if self.positions[node].y >= self.SCREEN_HEIGHT:
                self.positions[node].y = self.SCREEN_HEIGHT
            if self.positions[node].y < 0:
                self.positions[node].y = 0

        self.temperature *= self.TEMPERATURE_FACTOR
        self.iters += 1
            
    def eades(self):
        """
        Implementation of Eades' Spring Embedder algorithm for generating a layout for a network.
        """
        offset = {}

        for node in self.nodes:
            offset[node] = Vector2(0, 0)

        # Repulsion
        for node_a in self.nodes:
            for node_b in self.nodes:
                if node_a == node_b:
                    continue
                vec = self.positions[node_b] - self.positions[node_a]
                if vec.length() != 0:
                    offset[node_a] += (self.repulsion_constant / vec.length() ** 2) * vec.normalize()

        # Attraction
        for edge in self.edges:
            node_a = edge[0]
            node_b = edge[1]
            vec = self.positions[node_b] - self.positions[node_a]
            if vec.length() == 0:
                continue
            v = self.attraction_constant * log(vec.length() / self.ideal_length) * vec.normalize()
            offset[node_a] += v
            offset[node_b] -= v

        # Apply net force
        for node in self.nodes:
            if offset[node].magnitude() > self.temperature:
                offset[node] = offset[node].normalize()
                offset[node] *= self.temperature

            self.positions[node] += offset[node]

            if self.positions[node].x >= self.SCREEN_WIDTH:
                self.positions[node].x = self.SCREEN_WIDTH
            if self.positions[node].x < 0:
                self.positions[node].x = 0
            if self.positions[node].y >= self.SCREEN_HEIGHT:
                self.positions[node].y = self.SCREEN_HEIGHT
            if self.positions[node].y < 0:
                self.positions[node].y = 0

            self.temperature *= self.TEMPERATURE_FACTOR
            self.iters += 1

    def ajdust_node_positions(self):
        scale = min(
            ((self.SCREEN_WIDTH - 2 * self.PADDING) / self.max_x),
            ((self.SCREEN_HEIGHT - 2 * self.PADDING) / self.max_y)
        )
        # left_margin = (self.max_x - self.min_x) / 2
        for node in self.nodes:
            self.positions[node] = Vector2(
                int(self.PADDING + self.positions[node][0] * scale),
                int(self.PADDING + self.positions[node][1] * scale)
            )

    def render(self):
        self.render_graph()
        self.render_ants()

    def render_graph(self):
        self.screen.fill(self.BG_COLOR)
        for edge in self.edges:
            pygame.draw.aaline(self.screen, self.EDGE_COLOR, self.positions[edge[0]], self.positions[edge[1]])
        for node in self.nodes:
            pygame.draw.circle(self.screen, self.NODE_COLOR, self.positions[node], self.NODE_RADIUS)

            # gfxdraw.aacircle(self.screen, self.positions[node][0], self.positions[node][1], self.NODE_RADIUS, self.NODE_COLOR)
            # gfxdraw.filled_circle(self.screen, self.positions[node][0], self.positions[node][1], self.NODE_RADIUS, self.NODE_COLOR)

    # def update_ants(self):
    #     if self.start_of_turn:
    #         for _ in self.turns[self.turn]:
    #             self.ants.append(self.positions[self.start])
    #         self.start_of_turn = False
    #         return
    #     self.ants = [(ant[0] + 10, ant[1] + 10) for ant in self.ants]

    def render_ants(self):
        if self.turn >= len(self.turns):
            return 
        # for ant in self.ants:
        #     pygame.draw.circle(self.screen, self.ANT_COLOR, ant, self.ANT_RADIUS)
        for move in self.turns[self.turn]:
            pygame.draw.circle(self.screen, self.ANT_COLOR, self.positions[move], self.ANT_RADIUS)
        self.turn += 1

    def read_input(self):
        self.ant_count = int(sys.stdin.readline().strip('\n'))
        
        next_is_start = False
        while True:
            line = sys.stdin.readline().strip('\n')
            if line[0] == '#':
                if line == "##start":
                    next_is_start = True
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
            self.positions[node] = Vector2(x, y)
            if next_is_start:
                self.start = node
                next_is_start = False

        print(self.positions)

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
    if args.a == True:
        visualizer.set_random_xy()

    pygame.init()
    running = True
    while running:
        # visualizer.update_ants()
        if (args.a == True and visualizer.iters < visualizer.max_iters):
            visualizer.fruchterman_reingold()
        visualizer.render_graph()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False

        pygame.display.flip()
        pygame.time.delay(200)

    pygame.quit()

if __name__ == "__main__":
    main()
