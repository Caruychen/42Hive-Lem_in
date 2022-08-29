# Lem-in

![lem-in Visualization](https://github.com/Caruychen/image_media/blob/main/lem-in/My_Movie_AdobeExpress.gif)

## About
>Your ant colony must move from one point to another. How do you do it in the shortest time possible? This project is all about graph traversal: we built a program that intelligently decides paths and precise movements taken by the ants through an ant colony.

TLDR: An intelligent ant farm manager program.

## The Objective
To build a program that finds the quickest way to send **N** number of ants ants across an ant farm. An ant farm contains an arbitrary set of **rooms**, and **links** connecting any two rooms.
* The ant farm designates one **##start** room, and one **##end** room.
* Each room has a capacity of one ant only.

The **quickest way** means the solution that takes the **least number of turns** for all ants to travel from **##start** to **##end**. A turn is defined as a step from one room to the next.

_**To read more about the objective, data input format and problem constraints, follow the link to this [wiki-page](../../wiki/Objective)**_

## The Algorithm

## The Visualizer
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
