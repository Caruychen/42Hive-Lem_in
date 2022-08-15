from pygame import Vector2
from math import log

def fruchterman_reingold(visualizer):
    """
    Implementation of Fructherman and Reingold's force-directed graph drawing algorithm.
    """
    offset = {}
    for node in visualizer.nodes:
        offset[node] = Vector2(0, 0)

    # Repulsion
    for node_a in visualizer.nodes:
        for node_b in visualizer.nodes:
            if node_a == node_b:
                continue
            vec = visualizer.positions[node_b] - visualizer.positions[node_a]
            if vec.length() != 0:
                offset[node_a] += ((visualizer.ideal_length ** 2) / vec.length()) * vec.normalize()

    # Attraction
    for edge in visualizer.edges:
        node_a = edge[0]
        node_b = edge[1]
        vec = visualizer.positions[node_b] - visualizer.positions[node_a]
        if vec.length() != 0:
            v = ((vec.length() ** 2) / visualizer.ideal_length) * vec.normalize()
            offset[node_a] += v
            offset[node_b] -= v

    # Apply net force
    for node in visualizer.nodes:
        if offset[node].magnitude() > visualizer.temperature:
            offset[node] = offset[node].normalize()
            offset[node] *= visualizer.temperature

        visualizer.positions[node] += offset[node]

        if visualizer.positions[node].x >= visualizer.SCREEN_WIDTH:
            visualizer.positions[node].x = visualizer.SCREEN_WIDTH
        if visualizer.positions[node].x < 0:
            visualizer.positions[node].x = 0
        if visualizer.positions[node].y >= visualizer.SCREEN_HEIGHT:
            visualizer.positions[node].y = visualizer.SCREEN_HEIGHT
        if visualizer.positions[node].y < 0:
            visualizer.positions[node].y = 0

    visualizer.temperature *= visualizer.TEMPERATURE_FACTOR
    visualizer.iters += 1

def eades(visualizer):
    """
    Implementation of Eades' Spring Embedder algorithm for generating a layout for a network.
    """
    offset = {}

    for node in visualizer.nodes:
        offset[node] = Vector2(0, 0)

    # Repulsion
    for node_a in visualizer.nodes:
        for node_b in visualizer.nodes:
            if node_a == node_b:
                continue
            vec = visualizer.positions[node_b] - visualizer.positions[node_a]
            if vec.length() != 0:
                offset[node_a] += (visualizer.repulsion_constant / vec.length() ** 2) * vec.normalize()

    # Attraction
    for edge in visualizer.edges:
        node_a = edge[0]
        node_b = edge[1]
        vec = visualizer.positions[node_b] - visualizer.positions[node_a]
        if vec.length() == 0:
            continue
        v = visualizer.attraction_constant * log(vec.length() / visualizer.ideal_length) * vec.normalize()
        offset[node_a] += v
        offset[node_b] -= v

    # Apply net force
    for node in visualizer.nodes:
        if offset[node].magnitude() > visualizer.temperature:
            offset[node] = offset[node].normalize()
            offset[node] *= visualizer.temperature

        visualizer.positions[node] += offset[node]

        if visualizer.positions[node].x >= visualizer.SCREEN_WIDTH:
            visualizer.positions[node].x = visualizer.SCREEN_WIDTH
        if visualizer.positions[node].x < 0:
            visualizer.positions[node].x = 0
        if visualizer.positions[node].y >= visualizer.SCREEN_HEIGHT:
            visualizer.positions[node].y = visualizer.SCREEN_HEIGHT
        if visualizer.positions[node].y < 0:
            visualizer.positions[node].y = 0

        visualizer.temperature *= visualizer.TEMPERATURE_FACTOR
        visualizer.iters += 1
