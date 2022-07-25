/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_node.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:47:39 by cchen             #+#    #+#             */
/*   Updated: 2022/07/26 00:22:03 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *   Flow node represents the rooms of the ant nest network. Each node is an
 *   element of the adjacency list implemented as the flow_network data type.
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
 *   The flow node's ALIAS simply holds a string that is the name of the room
 *   The EDGES is a "bag" or vector (dynamic array) of edges, which are the
 *   links to adjacent rooms.
 *   The EDGES are of an iterable data type such as the vector, so they can be
 *   easily scanned as part of the Breadth First Seach pattern in the 
 *   edmunds-karp algorithm when identifying the paths with max-flow.
*/

#ifndef FLOW_NODE_H
# define FLOW_NODE_H

# include "flow_structs.h"

int			node_make(t_flow_node *node, char *alias, int x, int y);
int			node_push(t_flow_node *node, t_flow_edge *edge);
t_flow_edge	*node_get(t_flow_node *node, size_t index);
void		node_free(t_flow_node *node);

#endif
