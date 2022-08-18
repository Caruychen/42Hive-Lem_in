/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:51:52 by cchen             #+#    #+#             */
/*   Updated: 2022/08/18 10:46:01 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

/* ************************************************************************** */
/*                                   SOLVER                                   */
/******************************************************************************
 * The solver is based on the Edmonds-karp algorithm, which computes the 
 * "maximum flow" in a flow network.
 * Augmenting paths are found using Breadth First Search traversal to find
 * the shortest path first. Each iteration of BFS will return one additional
 * augmentable path.
 *
 * The network is then augmented given the newly identified augmentable path.
 * The new pathset is extracted from the network, and stored if the new
 * pathset takes fewer steps for all ants to traverse than the previous
 * pathset.
 *
 * The solver receives the following parameters:
 * 1. Network Graph
 * 2. Pathset
 *
 * Pseudo-code
 * input: network, pathset, output: OK, ERROR
 *   Initialise path count = 0
 *   Initialise "trace(edge_to, sink_edges)" to NULL
 *   While (Network has augmenting path(fills "trace"))
 *      Augment "network" given "trace(edge_to, sink_edges)"
 *      Extract new "pathset" given augmented "network"
 *      keep the best "pathset" so far (min-steps)
 *      increment path "count"
 *   Return ERROR if count == 0
 *   Assign ants to best path in "pathset" (minising steps).
 *   Return (OK);
 *****************************************************************************/
int	solve(t_flow_network *network, t_pathset *pathset);

#endif
