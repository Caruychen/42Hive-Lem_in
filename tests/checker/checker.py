import sys

BOLD = '\033[1m'
UNDERLINE = '\033[4m'
RED = "\u001b[31m"
END = "\u001b[0m"

def invalid_move(move, msg):
    print(RED + 'Invalid move >>' + END +' "' + move + '" ' + msg)

def main():
    print(BOLD + "Lem-in Checker 🐜" + END)

    lines = [line.strip('\n') for line in sys.stdin.readlines()]
    if not lines[0].isnumeric():
        print("Invalid ant number")
        sys.exit()
    ants = int(lines[0])
    source = None
    sink = None
    lines = lines[1:]
    map_lines = []
    solution_lines = []

    for i, line in enumerate(lines):
        if line.startswith('L'):
            map_lines = lines[:i]
            solution_lines = lines[i:]
            break

    if len(map_lines) == 0:
        print("Lem-in output contained no map info.")
        sys.exit()

    if len(solution_lines) == 0:
        print("Lem-in output contained no solution.")
        sys.exit()

    adjacency_list = dict()
    next_is_source = False
    next_is_sink = False
    for i, line in enumerate(map_lines):

        if line[0] == '#':
            if line == "##start":
                next_is_source = True
            elif line == "##end":
                next_is_sink = True
            continue

        split = line.split(' ')
        if len(split) == 1:
            map_lines = map_lines[i:]
            break
        node = split[0]
        adjacency_list[node] = []

        if next_is_source:
            source = node
            next_is_source = False
        elif next_is_sink:
            sink = node
            next_is_sink = False

    if sink == None:
        print("Input did not contain sink node")
        sys.exit()
    if source == None:
        print("Input did not contain source node")
        sys.exit()

    if map_lines[-1] != "":
        print(RED + "FAILED >> " + END + "Parser output was not followed by a newline.")

    for line in map_lines[:-1]:
        if line[0] == '#':
            continue
        node_a, node_b = line.split('-')
        adjacency_list[node_a].append(node_b)
        adjacency_list[node_b].append(node_a)

    # print("Adjacency list")
    # print(adjacency_list)
    if len(adjacency_list[sink]) == 0:
        print("Sink node has no neighbours")
        sys.exit()
    if len(adjacency_list[source]) == 0:
        print("Source node has no neighbours")
        sys.exit()

    print(UNDERLINE + "\nLem-in solution:" + END)
    if len(solution_lines) < 25:
        for line in solution_lines:
            print(line)
    else:
        print("Solution not printed, too many lines")

    print("Checking output...")

    expected_ant_id = 1
    ant_ids = []
    ants_in_sink = 0
    previous = ["" for _ in range(ants + 1)]
    for line in solution_lines:
        moves = line.split(' ')
        current_line_ant_ids = []
        for move in moves:

            if not move.startswith('L'):
                invalid_move(move, "Move should follow format L[ant number]-[room name]")

            split = move[1:].split('-')
            if len(split) != 2:
                invalid_move(move, "Move should follow format L[ant number]-[room name]")
                continue
            ant_id, room_alias = split

            if not ant_id.isnumeric():
                invalid_move(move, "Ant number should consist of only numbers")
            ant_id = int(ant_id)

            if ant_id not in ant_ids:
                if ant_id != expected_ant_id:
                    invalid_move(move, "Expected ant id to be " + str(expected_ant_id) + " but was " + str(ant_id))
                expected_ant_id += 1
                if room_alias not in adjacency_list[source]:
                    invalid_move(move, "Ant moved from source to a node that is not adjacent with source")
            elif room_alias not in adjacency_list[previous[ant_id]]:
                invalid_move(move, "Ant moved to a node that was not adjacent to the previous node")
            elif room_alias.startswith(('#', 'L')):
                invalid_move(move, "Room name should not begin with 'L' or '#'")

            if ant_id in current_line_ant_ids:
                invalid_move(move, "Ant already moved during this turn")
            ant_ids.append(ant_id)
            current_line_ant_ids.append(ant_id)

            if room_alias == sink:
                ants_in_sink += 1

            previous[ant_id] = room_alias

    if ants_in_sink != ants:
        print(RED + 'Invalid solution >>' + END + " Not all ants made it to the end of the graph")

if __name__ == "__main__":
    main()
