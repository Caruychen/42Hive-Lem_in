#!/usr/bin/env python3

from layout import eades, fruchterman_reingold
from parse import parse_input
from visualizer import Visualizer
from pygame import Vector2

import pygame
from argparse import ArgumentParser

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

    argparser.add_argument("-e", action = "store_true")
    argparser.add_argument("-f", action = "store_true")
    args = argparser.parse_args()

    pygame.init()
    pygame.event.set_allowed([pygame.QUIT, pygame.KEYDOWN, pygame.MOUSEWHEEL])
    visualizer = Visualizer()
    parse_input(visualizer)
    visualizer.adjust_node_positions()

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
            visualizer.render_text(visualizer.text_auto_layout)
            running = check_events(visualizer, exit_auto_layout)
            pygame.display.flip()

    while running:
        visualizer.render_graph()
        visualizer.render_ants()
        visualizer.render_text(visualizer.text_solution)
        running = check_events(visualizer, replay)
        pygame.display.flip()
        pygame.time.delay(200)

    pygame.quit()

if __name__ == "__main__":
    main()
