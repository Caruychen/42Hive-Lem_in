import sys
from pygame import Vector2

def parse_input(visualizer):
    visualizer.graph.ant_count = int(sys.stdin.readline().strip('\n'))
    
    next_is_start = False
    next_is_end = False
    while True:
        line = sys.stdin.readline().strip('\n')
        if line[0] == '#':
            if line == "##start":
                next_is_start = True
            elif line == "##end":
                next_is_end = True
            continue
        if not ' ' in line:
            break
        split = line.split(' ')
        x = int(split[1])
        y = int(split[2])
        visualizer.graph.max_x = max(visualizer.graph.max_x, x)
        visualizer.graph.max_y = max(visualizer.graph.max_y, y)
        visualizer.graph.min_x = min(visualizer.graph.min_x, x)
        visualizer.graph.min_y = min(visualizer.graph.min_y, y)
        node = split[0]
        visualizer.graph.nodes.append(node)
        visualizer.graph.positions[node] = Vector2(x, y)
        if next_is_start:
            visualizer.graph.start = node
            next_is_start = False
        elif next_is_end:
            visualizer.graph.end = node
            next_is_end = False

    if not line[0] == '#':
        visualizer.graph.edges.append(line.split('-'))

    while True:
        line = sys.stdin.readline().strip('\n')
        if len(line) == 0:
            break
        if line[0] == '#':
            continue
        if not '-' in line:
            break
        visualizer.graph.edges.append(line.split('-'))

    solution_lines = [l.strip('\n ') for l in sys.stdin.readlines()]
    for line in solution_lines:
        if len(line) == 0:
            break
        splits = line.split(' ')
        visualizer.turns.append(list(split.split('-')[1] for split in splits if split.startswith('L')))

    paths = {}
    for i, e in enumerate(visualizer.turns[0]):
        paths[str(i + 1)] = [e]
    for line in solution_lines[1:]:
        split = line.split(' ')
        for move in split:
            ant_id, node = move[1:].split('-')
            if ant_id in paths:
                paths[ant_id].append(node)
    visualizer.graph.paths = paths
            
