#!/usr/bin/env python3

import sys
import os
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "hide"
import pygame
from layout import fruchterman_reingold
from parse import parse_input
from visualizer import Visualizer
from pygame import Vector2
from argparse import ArgumentParser

USAGE = "Usage: ./lem-in < map | ./main.py\n  -f\tForce-directed graph layout"

def exit_auto_layout(visualizer):
    visualizer.iters = visualizer.max_iters

def replay(visualizer):
    visualizer.turn = 0

def check_events(visualizer, space_function):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    return False
                if event.key == pygame.K_SPACE:
                    space_function(visualizer)
            if event.type == pygame.MOUSEWHEEL: 
                visualizer.graph.zoom(Vector2(pygame.mouse.get_pos()), event.y)
        return True
            
def main():
    argparser = ArgumentParser(description="Visualizes your Lem-in.")

    argparser.add_argument("-f", action = "store_true")
    args = argparser.parse_args()

    if os.isatty(sys.stdin.fileno()):
        print(USAGE)
        sys.exit()

    pygame.init()
    pygame.event.set_allowed([pygame.QUIT, pygame.KEYDOWN, pygame.MOUSEWHEEL])
    visualizer = Visualizer()

    parse_input(visualizer)
    visualizer.adjust_node_positions()

    running = True

    if args.f is True:
        visualizer.set_random_xy()
        while running and visualizer.iters < visualizer.max_iters:
            fruchterman_reingold(visualizer)
            visualizer.render_bg()
            visualizer.render_edges()
            visualizer.render_nodes()
            visualizer.render_text(visualizer.text_auto_layout)
            running = check_events(visualizer, exit_auto_layout)
            pygame.display.flip()

    while running:
        visualizer.render_bg()
        visualizer.render_edges()
        visualizer.render_paths()
        visualizer.render_nodes()
        visualizer.render_ants()
        visualizer.render_text(visualizer.text_solution)
        running = check_events(visualizer, replay)
        pygame.display.flip()
        pygame.time.delay(200)

    pygame.quit()

if __name__ == "__main__":
    main()
