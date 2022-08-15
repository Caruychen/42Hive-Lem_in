#!/usr/bin/env python3

from layout import eades, fruchterman_reingold
from parse import parse_input
from visualizer import Visualizer

import pygame
from pygame import Vector2
from random import randint
from argparse import ArgumentParser


def handle_events():
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    return False
        return True
            
def main():
    argparser = ArgumentParser(description="Visualizes your Lem-in.")

    argparser.add_argument("-e", action = "store_true")
    argparser.add_argument("-f", action = "store_true")
    args = argparser.parse_args()

    visualizer = Visualizer()
    parse_input(visualizer)
    visualizer.ajdust_node_positions()

    pygame.init()

    running = True

    auto_layout = None
    if args.e == True:
        auto_layout = eades
    if args.f == True:
        auto_layout = fruchterman_reingold
    if auto_layout is not None:
        visualizer.set_random_xy()
        while running and visualizer.iters < visualizer.max_iters:
            auto_layout(visualizer)
            visualizer.render_graph()
            running = handle_events()
            pygame.display.flip()
            pygame.time.delay(200)

    while running:
        visualizer.render_graph()
        visualizer.render_ants()
        running = handle_events()
        pygame.display.flip()
        pygame.time.delay(200)

    pygame.quit()

if __name__ == "__main__":
    main()
