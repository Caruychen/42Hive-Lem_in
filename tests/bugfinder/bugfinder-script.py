import os
import uuid
from tempfile import TemporaryDirectory, TemporaryFile
from subprocess import run, PIPE
import random

print("Lem-in bugfinder 🔍")

script_dir = os.path.dirname(os.path.realpath(__file__))
rootdir = os.path.abspath(os.path.join(__file__, "../../.."))
mapdir = os.path.abspath(os.path.join(script_dir, "maps/"))

lem_in_binary = os.path.join(rootdir, "lem-in")
if not os.path.exists(lem_in_binary):
    print("Error: could not find lem-in executable.")

generator_binary = os.path.join(rootdir, "generator")
if not os.path.exists(lem_in_binary):
    print("Error: could not find generator executable.")

if not os.path.exists(mapdir):
    os.mkdir(mapdir)

mapnumber = 0
for path in os.scandir(mapdir):
    if path.is_file():
        mapnumber += 1
mapnumber += 1

generator_flag_list = ["--flow-one", "--flow-ten", "--flow-thousand", "--big", "--big-superposition"]

with TemporaryDirectory() as tmpdir:

    print("Generating maps and testing...")

    for _ in range(100):
        generator_flag = random.choice(generator_flag_list)
        maptype = generator_flag.strip('-')
        mapname = tmpdir + str(uuid.uuid4().hex)

        fd = os.open(mapname, os.O_RDWR | os.O_CREAT)
        gen_result = run([generator_binary, generator_flag], stdout = fd)

        fd = os.open(mapname, os.O_RDWR | os.O_CREAT)
        with TemporaryFile() as tmp:

            lem_in_result = run([lem_in_binary, "-q"], stdin = fd, stdout = PIPE, universal_newlines = True)
            output_lines = lem_in_result.stdout.split('\n')

            steps_required = int(output_lines[1].split(' ')[7])
            steps_taken = int(output_lines[2].split(' ')[2])

            if steps_required != steps_taken:
                print("Map found. Steps required: " + str(steps_required) + ". Steps taken: " + str(steps_taken) + ".")
                new_mapname = mapdir + "/" + maptype
                if steps_taken > steps_required:
                    new_mapname = new_mapname + "-more-"
                else:
                    new_mapname = new_mapname + "-less-"
                new_mapname = new_mapname + str(mapnumber)
                mapnumber += 1
                os.rename(mapname, new_mapname)
