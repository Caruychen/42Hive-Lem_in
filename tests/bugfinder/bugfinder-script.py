import os
import uuid
from tempfile import TemporaryDirectory, TemporaryFile
from subprocess import run, PIPE

print("Lem-in bugfinder 🔍")

script_dir = os.path.dirname(os.path.realpath(__file__))
# tempdir = os.path.abspath(os.path.join(__file__, "temp/"))
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

with TemporaryDirectory() as tmpdir:

    print("Generating maps and testing...")

    mapname = tmpdir + str(uuid.uuid4().hex)
    fd = os.open(mapname, os.O_RDWR | os.O_CREAT)

    gen_result = run([generator_binary, "--flow-one"], stdout = fd)

    fd = os.open(mapname, os.O_RDWR | os.O_CREAT)
    with TemporaryFile() as tmp:
        lem_in_result = run([lem_in_binary, "-q"], stdin = fd, stdout = PIPE, universal_newlines = True)
        output_lines = lem_in_result.stdout.split('\n')
        steps_required = int(output_lines[1].split(' ')[7])
        steps_taken = int(output_lines[2].split(' ')[2])
        print("Steps required by generator: " + str(steps_required))
        print("Steps taken: " + str(steps_taken))
