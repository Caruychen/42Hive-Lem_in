import random
import string
import os
import sys

def get_random_string_lower(length):
    return_str = "".join(random.choice(string.ascii_lowercase) for i in range(length))
    return return_str

def get_random_string_alnum(length):
    return_str = "".join(random.choice(string.ascii_letters + string.digits) for i in range(length))
    return return_str

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 mapgen.py [number of rooms] [number of links]")
        exit()

    room_count = int(sys.argv[1])
    link_count = int(sys.argv[2])
    rooms = []
    links = []

    source_index = random.randint(0, room_count - 1)
    sink_index = random.randint(0, room_count - 1)
    while sink_index == source_index:
        sink_index = random.randint(0, room_count - 1)

    filename = "test-" + get_random_string_lower(5)

    f = open(filename, "w")

    # Ant number
    f.write(str(random.randint(0, 1000)) + "\n")

    # Rooms
    for i in range(room_count):
        if i == source_index:
            f.write("##start\n")
        elif i == sink_index:
            f.write("##end\n")
        room_name = get_random_string_alnum(random.randint(0, 20))
        if room_name[0] == 'L':
            room_name = room_name[1:]
        if i == source_index:
            source_room_name = room_name
        elif i == sink_index:
            sink_room_name = room_name
        f.write(room_name
                + " " + str(random.randint(0, 100))
                + " " + str(random.randint(0, 100))
                + "\n")
        rooms.append(room_name)

    # Links
    for _ in range(link_count):
        i = random.randint(0, room_count - 1)
        j = random.randint(0, room_count - 1)
        while i == j:
            j = random.randint(0, room_count - 1)
        f.write(rooms[i] + "-" + rooms[j] + "\n")

if __name__ == "__main__":
    main()
