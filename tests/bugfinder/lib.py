import os

def get_steps(output_lines):
    steps_required = 0
    steps_taken = 0
    i = 0
    while i < len(output_lines):
        if output_lines[i].startswith("#Here is the number of lines required"):
            steps_required = int(output_lines[i].split(' ')[7])
            break
        i += 1
    while i < len(output_lines):
        if output_lines[i].startswith("L"):
            steps_taken += 1
        i += 1
    return (steps_required, steps_taken)

def calc_mapnumber(mapdir):
    mapnumber = 0
    for path in os.scandir(mapdir):
        if path.is_file():
            mapnumber += 1
    mapnumber += 1
    return mapnumber
