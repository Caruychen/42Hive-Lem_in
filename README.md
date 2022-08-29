# Lem-in

## About

>Your ant colony must move from one point to another. How do you do it in the shortest time possible? This project is all about graph traversal: we built a program that intelligently decides paths and precise movements taken by the ants through an ant colony.

TLDR: An intelligent ant farm manager program.

## The Problem

### Objective
Given **N** number of ants, and data describing the **rooms** and **links** in an ant farm, our program must find the quickest way to get **N** ants across the farm.

The quickest way means the solution that takes the least number of turns. A turn is defined as a step from one room to the next.

### Data inputs
The program receives the following data describing the ant farm from the standard output:
* **Number of ants**: Always an integer in the first line.
* **The rooms**: Formatted as follows `[name] [coord_x] [coord_y]`
* **The links**: Formatted as follows `[name1]-[name2]`

There are some additional input types in the data:
* **Commands**: Lines starting with `##` are commands modifying the properties of the line that come right after. Two mandatory commands are:
  * `##start` which signals the entrance
  * `##end` which signals the exit
* **Comments**: Lines are broken by comments which start with `#`. Comments are ignored by the program.

The ant farm input data may look like this:
```
42
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
#another comment
```

Which corrresponds to the following representation:
```
           _______________
         /                \
 ______[5]----[3]----[1]   |
/              |     /     |
[6]-----[0]----[4]  /      |
\    _________/ |  /       |
 \  /          [2]/_______/
  [7]_________/
						
```

### Problem constraints


## The Algorithm

### Visualizer
As a bonus, we've implemented a visualizer that renders the graph and animates the ants traversing the graph. The visualizer is written in Python using the Pygame library. To use the visualizer you first have to install Pygame.
```
pip3 install pygame
```
To launch the visualizer, pipe the standard output of Lem-in to the visualizer.
```
./lem-in < map | ./visualizer/main.py
```
By default the visualizer uses the given node coordinates. Sometimes maps will have coordinates that are useless for visualization. This is the case with the coordinates given by the official Lem-in generator. To render such maps in a meaningful way, we've implemented Fruchterman & Reingold's force directed graph drawing algorithm. Launch the visualizer with the `-f` flag to automatically generate a layout for the graph.
```
./lem-in < map | ./visualizer/main.py -f
```
After using the visualizer you may want to remove Pygame. You can do this using `pip3 uninstall pygame`.

https://user-images.githubusercontent.com/65853349/186159171-2c298c57-b17d-45d7-a06c-aaba87b988c4.mov
