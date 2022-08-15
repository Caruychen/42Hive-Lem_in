#!/usr/bin/env python3

from layout import eades, fruchterman_reingold
from parse import parse_input
from graph import Graph

import sys
import pygame
from pygame import Vector2
from random import randint
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

        self.ants = []

        self.turns = []
        self.turn = 0
        self.start_of_turn = True

        self.ideal_length = 10
        self.repulsion_constant = 2.0
        self.attraction_constant = 1.0
        self.temperature = 100
        self.iters = 0
        self.max_iters = 1000
        self.center = Vector2(self.SCREEN_WIDTH / 2, self.SCREEN_HEIGHT / 2)

        self.screen = pygame.display.set_mode((self.SCREEN_WIDTH, self.SCREEN_HEIGHT))
        pygame.display.set_caption("Lem-in Visualizer")

    def set_random_xy(self):
        for node in self.graph.nodes:
            self.graph.positions[node] = Vector2(randint(0, self.SCREEN_WIDTH), randint(0, self.SCREEN_HEIGHT))
            

    def ajdust_node_positions(self):
        scale = min(
            ((self.SCREEN_WIDTH - 2 * self.PADDING) / self.graph.max_x),
            ((self.SCREEN_HEIGHT - 2 * self.PADDING) / self.graph.max_y)
        )
        for node in self.graph.nodes:
            self.graph.positions[node] = Vector2(
                int(self.PADDING + self.graph.positions[node][0] * scale),
                int(self.PADDING + self.graph.positions[node][1] * scale)
            )

    def render(self):
        self.render_graph()
        self.render_ants()

    def render_graph(self):
        self.screen.fill(self.BG_COLOR)
        for edge in self.graph.edges:
            pygame.draw.aaline(self.screen, self.EDGE_COLOR, self.graph.positions[edge[0]], self.graph.positions[edge[1]])
        for node in self.graph.nodes:
            pygame.draw.circle(self.screen, self.NODE_COLOR, self.graph.positions[node], self.NODE_RADIUS)

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
            pygame.draw.circle(self.screen, self.ANT_COLOR, self.graph.positions[move], self.ANT_RADIUS)
        self.turn += 1

            
def main():
    argparser = ArgumentParser(description="Visualizes your Lem-in.")

    argparser.add_argument("-a", action = "store_true")
    args = argparser.parse_args()

    visualizer = Visualizer()
    parse_input(visualizer)
    visualizer.ajdust_node_positions()
    if args.a == True:
        visualizer.set_random_xy()

    pygame.init()
    running = True
    while running:
        # visualizer.update_ants()
        if (args.a == True and visualizer.iters < visualizer.max_iters):
            fruchterman_reingold(visualizer)
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
