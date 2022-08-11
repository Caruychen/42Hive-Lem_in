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
    MAX_FPS = 60
    FONT_SIZE = 20
    BG_COLOR = (80, 43, 58)
    TEXT_COLOR = (249, 226, 125)
    EDGE_COLOR = (255, 141, 109)
    NODE_COLOR = (255, 88, 93)
    ANT_COLOR = (255, 198, 88)

    def __init__(self):
        self.ants = 0
        self.nodes = []
        self.edges = []
        self.screen = pygame.display.set_mode((self.SCREEN_WIDTH, self.SCREEN_HEIGHT))
        pygame.display.set_caption("Lem-in Visualizer")

    def render(self):
        self.screen.fill(self.BG_COLOR)

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
            self.nodes.append(Node(split[0], int(split[1]), int(split[2])))

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
