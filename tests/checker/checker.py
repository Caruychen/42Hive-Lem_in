import sys

BOLD = '\033[1m'
UNDERLINE = '\033[4m'
RED = "\u001b[31m"
END = "\u001b[0m"

def main():
    print(BOLD + "Lem-in Checker 🐜" + END)

    lines = [line.strip('\n') for line in sys.stdin.readlines()]
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

    print(UNDERLINE + "\nLem-in solution:" + END)
    for line in solution_lines:
        print(line)

    def invalid(token):
        print(RED + 'FAILED >>' + END +' "' + token + '"')
        # sys.exit()

    print("Checking output...")

    expected_ant_id = 1
    ant_ids = []
    previous = ["" for _ in range(ants + 1)]
    for line in solution_lines:
        tokens = line.split(' ')
        current_line_ant_ids = []
        for token in tokens:

            if not token.startswith('L'):
                invalid(token)

            split = token[1:].split('-')
            if len(split) != 2:
                invalid(token)
                continue
            ant_id, room_alias = split

            if not ant_id.isnumeric():
                invalid(token)
            ant_id = int(ant_id)

            if ant_id not in ant_ids:
                if ant_id != expected_ant_id:
                    print("Expected ant id to be " + str(expected_ant_id) + " but was " + str(ant_id))
                expected_ant_id += 1
                if room_alias not in adjacency_list[source]:
                    print("Ant moved from source to a node that is not adjacent with source")
            elif room_alias not in adjacency_list[previous[ant_id]]:
                print("Ant moved to a node that was not adjacent to the previous node")
            elif room_alias.startswith(('#', 'L')):
                invalid(token)
            if ant_id in current_line_ant_ids:
                print("Ant already moved during this turn")
            ant_ids.append(ant_id)
            current_line_ant_ids.append(ant_id)

            previous[ant_id] = room_alias

if __name__ == "__main__":
    main()
