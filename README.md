# Lem-in
## About
>Your ant colony must move from one point to another. How do you do it in the shortest time possible? This project is all about graph traversal: we built a program that intelligently decides paths and precise movements taken by the ants through an ant farm.

TLDR: An intelligent ant farm manager program.

![lem-in Visualization](https://github.com/Caruychen/image_media/blob/main/lem-in/My_Movie_AdobeExpress.gif)

## The Objective
To build a program that finds the quickest way to send **N** number of ants ants across an ant farm. An ant farm contains an arbitrary set of **rooms**, and **links** connecting any two rooms.
* The ant farm designates one **##start** room, and one **##end** room.
* Each room has a capacity of one ant only.

The **quickest way** means the solution that takes the **least number of turns** for all ants to travel from **##start** to **##end**. A turn is defined as a step from one room to the next.

_**To read more about the objective, data input format and problem constraints, follow the link to this [wiki-page](../../wiki/Objective)**_

## The Algorithm
The algorithm is a modification of the [Edmonds-Karp](https://en.wikipedia.org/wiki/Edmonds–Karp_algorithm) algorithm. The original Edmonds-Karp algorithm derives a **flow-state** of a network, and the **maximum flow value** of the network, using a breadth first search pattern. What we are trying to find however, is:
* The optimal multiple shortest paths in a given **network** for **N** number of ants.

To do this, we modify the algorithm to do the following:
* Extract the **path set** of flows at any given **flow state** of a network.
* Determine the **optimal** paths set that minimises the number of steps for **N** ants to traverse the network
* Allocate ants across the optimal path set to achieve the minimum traversal steps.

### Modified Edmonds-Karp
The resulting algorithm is as follows:

* Start with flow = 0 for each **edge**
* While (there exists an augmenting path)
    * Find a path **P** in the **residual network**
    * **Augment** flow along path **P**
	* Derive a **pathset** from flow Network
    * Keep the best **pathset** seen so far
* Assign ants to path set

_**To read more about the algorithm, follow the link to this [wiki-page](https://github.com/Caruychen/42Hive-Lem_in/wiki/Algorithm)**_

## Data structure
We chose to represent the ant farm network by implementing an [Adjacency list](https://en.wikipedia.org/wiki/Adjacency_list).

We chose an adjacency list due to the greater space efficiencies it offerse for more sparce graphs. The space usage of an adjacency list is proportional to the number of edges and vertices in a graph. This is an improvement over an adjacency matrix, which uses space proportional to the square of the number of vertices.

Adjacency lists are also more efficient in the operations performed. The neighbours of each node can be listed in time proprtional to the degree ofthe node. For adjacency matrices however, this takes time proportional tothe number of vertices in the graph, which may be significantly higher than the degree.  The main trade off of using adjacency lists however, is that it is slower to test whether two vertices are adjacent to each other.

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
