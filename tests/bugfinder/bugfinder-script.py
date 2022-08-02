import os
import uuid
from tempfile import TemporaryDirectory
from subprocess import run

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

    print("Running matches")

    mapname = str(uuid.uuid4().hex)
    fd = os.open(tmpdir + mapname, os.O_RDWR | os.O_CREAT)
    gen_result = run([generator_binary, "--flow-one"], stdout = fd)
    # print(gen_result)
    # restuil = run("./../../lem-in < testmap")
