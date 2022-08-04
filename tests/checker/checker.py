import os, sys
import re

BOLD = '\033[1m'
RED = "\u001b[31m"
ENDCOLOR = "\u001b[0m"

print("Lem-in Checker 🐜")

lines = [line.strip('\n') for line in sys.stdin.readlines()]

for i, line in enumerate(lines):
    if line.startswith('L'):
        lines = lines[i:]
        break

print("\nLem-in output:")
for line in lines: print(line)

def invalid(token):
    print(RED + 'FAILED >>' + ENDCOLOR +' "' + token + '"')
    sys.exit()

print("Checking output...")

for line in lines:
    ant_numbers = []
    tokens = line.split(' ')
    for token in tokens:
        if not token.startswith('L'):
            invalid(token)
        ant_number, room_alias = token[1:].split('-')
        if not ant_number.isnumeric():
            invalid(token)
        if room_alias.startswith(('#', 'L')):
            invalid(token)
        if ant_number in ant_numbers:
            invalid(token)
        ant_numbers.append(ant_number)
