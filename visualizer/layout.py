from pygame import Vector2

def fruchterman_reingold(visualizer):
    """
    Implementation of Fructherman and Reingold's force-directed graph drawing algorithm.
    """
    offset = {}
    for node in visualizer.graph.nodes:
        offset[node] = Vector2(0, 0)

    # Repulsion
    for node_a in visualizer.graph.nodes:
        for node_b in visualizer.graph.nodes:
            if node_a == node_b:
                continue
            vec = visualizer.graph.positions[node_b] - visualizer.graph.positions[node_a]
            if vec.length() != 0:
                offset[node_b] += ((visualizer.ideal_length ** 2) / vec.length()) * vec.normalize()

    # Attraction
    for edge in visualizer.graph.edges:
        node_a = edge[0]
        node_b = edge[1]
        vec = visualizer.graph.positions[node_b] - visualizer.graph.positions[node_a]
        if vec.length() != 0:
            v = ((vec.length() ** 2) / visualizer.ideal_length) * vec.normalize()
            offset[node_a] += v
            offset[node_b] -= v

    # Apply net force
    for node in visualizer.graph.nodes:
        if offset[node].magnitude() > visualizer.temperature:
            offset[node] = offset[node].normalize()
            offset[node] *= visualizer.temperature

        visualizer.graph.positions[node] += offset[node]

        if visualizer.graph.positions[node].x >= visualizer.SCREEN_WIDTH:
            visualizer.graph.positions[node].x = visualizer.SCREEN_WIDTH
        if visualizer.graph.positions[node].x < 0:
            visualizer.graph.positions[node].x = 0
        if visualizer.graph.positions[node].y >= visualizer.SCREEN_HEIGHT:
            visualizer.graph.positions[node].y = visualizer.SCREEN_HEIGHT
        if visualizer.graph.positions[node].y < 0:
            visualizer.graph.positions[node].y = 0

    visualizer.temperature *= visualizer.TEMPERATURE_FACTOR
    visualizer.iters += 1
