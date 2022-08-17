/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_node.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:47:39 by cchen             #+#    #+#             */
/*   Updated: 2022/08/17 16:24:40 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               FLOW_NODE                                    */
/******************************************************************************
 *   Flow node represents a room of the ant nest network. Each node is an
 *   element of the flow_network adjacency list.
 *   
 *   The flow node data type:
 *    ---------------
 *   | ALIAS | EDGES | 
 *    ---------------
 *      |        |
 *      |       \ /                   
 *      |        --------------------------------
 *      |       | edge_0 | edge_1 | edge_2 | ... | } --> t_vec
 *      |        --------------------------------
 *     \ /                            / \
 *       -----------                   |
 *      | char *str |                  DATA TYPE: t_flow_edge
 *       -----------
 *
 *   The ALIAS holds a string that is the name of the room
 *   The EDGES is a "bag" or vector (dynamic array) of edges, which are the
 *   links to adjacent rooms.
 *   The EDGES are an iterable data type (vector), so they can be
 *   easily scanned as part of the Breadth First Seach pattern in the 
 *   edmunds-karp algorithm when identifying the paths with max-flow.
 *
 *   Additional Data Fields:
 *   * dst_to_start: The Distance to Start node
 *   	* The BFS algorithm accumulates and stores the computed distance
 *   	  to the stating node for each node traversed.
 *   * dst_to_end: The Distance to End node
 *   	* When Extracting path sets from the network. The distance to
 *   	  the end node is computed for each node that is in the path.
 *   * is_free:
 *   	* Indicates whether the node is part of a chosen path or not.
 *   	  0 = Not free, 1 = Free
 *   * is_via_augment:
 *      * Used internally during each BFS iteration. Stores whether
 *        the node was accessed via another free node, or a non-free node.
 *        0 = Accessed through a free node, 1 = Accessed through a non-free node
 *
 *   is_free & is_via_augment are primarily used in conjunction to prevent BFS
 *   from entering a taken node on a path, and exiting the same node to a
 *   free node immediately. (This would otherwise lead to paths crossing 
 *   each other).
 *
 *   dst_to_start & dst_to_end are used together to help select the most
 *   optimal augmentation to an existing path. A single path may have multiple
 *   alternative paths (that lead from a given node on the path, to the start),
 *   these fields are used to help select the shortest path.
 *****************************************************************************/

#ifndef FLOW_NODE_H
# define FLOW_NODE_H

# include "flow.h"

/* Node API */
int			node_make(t_flow_node *node, char *alias, int x, int y);
int			node_push(t_flow_node *node, t_flow_edge *edge);
t_flow_edge	*node_get(t_flow_node *node, size_t index);
void		node_free(t_flow_node *node);

#endif
