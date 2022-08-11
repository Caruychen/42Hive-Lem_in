#!/usr/bin/env python3

import sys
import argparse
import pygame
from dataclasses import dataclass

@dataclass
class Node:
    name: str
    x: int
    y: int

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
    NODE_RADIUS = 5

    def __init__(self):
        self.ants = 0
        self.max_x = 0
        self.max_y = 0
        self.nodes = []
        self.edges = []
        self.scale = 1
        self.screen = pygame.display.set_mode((self.SCREEN_WIDTH, self.SCREEN_HEIGHT))
        pygame.display.set_caption("Lem-in Visualizer")

    def set_scale(self):
        self.scale = (self.SCREEN_WIDTH - self.PADDING) / self.max_x

    def render(self):
        self.screen.fill(self.BG_COLOR)
        for node in self.nodes:
            pygame.draw.circle(self.screen, self.NODE_COLOR, (node.x * self.scale, node.y *self.scale), self.NODE_RADIUS)

    def read_input(self):
        self.ants = int(sys.stdin.readline().strip('\n'))
        
        while True:
            line = sys.stdin.readline().strip('\n')
            print(line)
            if line[0] == '#':
                continue
            if not ' ' in line:
                break
            split = line.split(' ')
            x = int(split[1])
            if x > self.max_x:
                self.max_x = x
            y = int(split[2])
            if y > self.max_y:
                self.max_y = y
            self.nodes.append(Node(split[0], x, y))

        while True:
            line = sys.stdin.readline().strip('\n')
            print(line)
            if len(line) == 0:
                break
            if line[0] == '#':
                continue
            if not '-' in line:
                break
            self.edges.append(line.split('-'))

        print(self.nodes)
        print(self.edges)

def main():
    argparser = argparse.ArgumentParser(description = "Visualize your Lem-in.")

    visualizer = Visualizer()
    visualizer.read_input()
    visualizer.set_scale()

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

    pygame.quit()

if __name__ == "__main__":
    main()
