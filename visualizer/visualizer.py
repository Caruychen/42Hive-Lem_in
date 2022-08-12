#!/usr/bin/env python3

import sys
import pygame
from pygame import Vector2
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
    NODE_RADIUS = 6
    TEMPERATURE_FACTOR = 0.95

    def __init__(self):
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
        self.repulsion_constant = 2500
        self.attraction_constant = 0.03
        self.temperature = 100
        self.start_of_turn = True
        self.iters = 0
        self.max_iters = 100
        self.center = Vector2(self.SCREEN_WIDTH / 2, self.SCREEN_HEIGHT / 2)
        self.screen = pygame.display.set_mode((self.SCREEN_WIDTH, self.SCREEN_HEIGHT))
        pygame.display.set_caption("Lem-in Visualizer")

    def auto_layout(self):
        offset = {}

        for node in self.nodes:
            offset[node] = Vector2(0, 0)

        for node_a in self.nodes:
            for node_b in self.nodes:
                if node_a != node_b:
                    print('a', self.positions[node_a])
                    print('b', self.positions[node_b])
                    vec = self.positions[node_b] - self.positions[node_a]
                    print('vec', vec)
                    dist = vec.magnitude()
                    print('dist', dist)
                    dist = max(0.1, dist)
                    repulsion = self.repulsion_constant / dist
                    vec = vec.normalize()
                    print('uv', vec)
                    vec = vec * repulsion * -1
                    print('repulsion', vec)
                    offset[node_a] += vec

        for edge in self.edges:
            node_a = edge[0]
            node_b = edge[1]
            vec = self.positions[node_b] - self.positions[node_a]
            dist = vec.magnitude()
            attraction = self.attraction_constant * dist**2
            vec = vec.normalize()
            vec *= attraction
            offset[node_a] += vec
            offset[node_b] -= vec

        for node in self.nodes:
            vec = self.center - self.positions[node]
            dist = vec.magnitude()
            gravity = self.attraction_constant / 8 * dist**2
            vec = vec.normalize()
            vec *= gravity
            offset[node] += vec

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
            self.positions[node] = (x, y)
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

    pygame.init()
    running = True
    while running:
        # visualizer.update_ants()
        if (args.a == True and visualizer.iters < visualizer.max_iters):
            visualizer.auto_layout()
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
