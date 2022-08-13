#!/usr/bin/env python3

import os
import sys
import uuid
from tempfile import TemporaryDirectory, TemporaryFile
from subprocess import run, PIPE
import random
import shutil
from io import BytesIO

print("Lem-in bugfinder 🔍")

script_dir = os.path.dirname(os.path.realpath(__file__))
rootdir = os.path.abspath(os.path.join(__file__, "../../.."))
mapdir = os.path.abspath(os.path.join(script_dir, "maps/"))

lem_in_binary = os.path.join(rootdir, "lem-in")
if not os.path.exists(lem_in_binary):
    print("Error: could not find lem-in executable.")

generator_binary = os.path.join(rootdir, "generator")
if not os.path.exists(generator_binary):
    print("Error: could not find generator executable.")

checker_script = os.path.join(rootdir, "tests/checker/checker.py")
if not os.path.exists(checker_script):
    print("Error: could not find checker script.")

if not os.path.exists(mapdir):
    os.mkdir(mapdir)

mapnumber = 0
for path in os.scandir(mapdir):
    if path.is_file():
        mapnumber += 1
mapnumber += 1

number_of_tests = 60

generator_flag_list = ["--flow-one",
                        "--flow-ten",
                        "--flow-thousand",
                        "--big",
                        "--big-superposition"]

if len(sys.argv) > 1 and sys.argv[1].isdigit():
    number_of_tests = int(sys.argv[1])

with TemporaryDirectory() as tmpdir:

    print("Generating maps and testing...")

    for _ in range(number_of_tests):
        generator_flag = random.choice(generator_flag_list)
        maptype = generator_flag.strip('-')
        mapname = tmpdir + str(uuid.uuid4().hex)

        fd = os.open(mapname, os.O_RDWR | os.O_CREAT)
        gen_result = run([generator_binary, generator_flag], stdout = fd)
        os.close(fd)

        fd = os.open(mapname, os.O_RDWR | os.O_CREAT)
        with TemporaryFile() as tmp:

            lem_in_result = run([lem_in_binary],
                                stdin = fd,
                                stdout = PIPE,
                                universal_newlines = True)

            if lem_in_result.returncode != 0:
                print("Map found. Lem-in raised an error.", end = "")
                new_mapname = maptype + "-error-" + str(mapnumber)
                print(" Saved as " + new_mapname + ".")
                new_mapname = mapdir + "/" + new_mapname
                mapnumber += 1
                shutil.move(mapname, new_mapname)
                os.close(fd)
                continue
             
            with TemporaryFile(mode = "w") as tmp_output:
                tmp_output.write(lem_in_result.stdout)
                tmp_output.seek(0)
                checker_result = run([checker_script],
                                     stdin = tmp_output,
                                     stdout = PIPE,
                                     universal_newlines = True)

                if checker_result.stdout.split('\n')[-2] != "Solution was correct.":
                    print("Map found. Checker found an error.", end = "")
                    new_mapname = maptype + "-invalid-" + str(mapnumber)
                    print(" Saved as " + new_mapname + ".")
                    new_mapname = mapdir + "/" + new_mapname
                    mapnumber += 1
                    shutil.move(mapname, new_mapname)
                    os.close(fd)
                    continue

            os.close(fd)
            fd = os.open(mapname, os.O_RDWR | os.O_CREAT)

            lem_in_result = run([lem_in_binary, "-q"],
                                stdin = fd,
                                stdout = PIPE,
                                universal_newlines = True)

            output_lines = lem_in_result.stdout.split('\n')

            steps_required = int(output_lines[1].split(' ')[7])
            steps_taken = int(output_lines[2].split(' ')[2])

            if steps_taken > steps_required:
                print("Map found. Steps required: "
                          + str(steps_required)
                          + ". Steps taken: "
                          + str(steps_taken) + ".", end = "")
                new_mapname = maptype + "-more-"
                new_mapname = new_mapname + str(mapnumber)
                print(" Saved as " + new_mapname + ".")
                new_mapname = mapdir + "/" + new_mapname
                mapnumber += 1
                shutil.move(mapname, new_mapname)
                os.close(fd)

print("Done.")
