/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:04:24 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 11:14:36 by cchen            ###   ########.fr       */
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

#include "lem_in.h"
#include "libft.h"

int	node_make(t_flow_node *node, char *alias)
{
	node->alias = alias;
	return (vec_new(&(node->edges), 1, sizeof(t_flow_edge *)));
}

/* This may or may not work, since vec_push expects a single void * pointer */
int	node_push(t_flow_node *node, t_flow_edge *edge)
{
	return (vec_push(&(node->edges), (void *) &edge));
}

void	node_free(t_flow_node *node)
{
	if (node->alias != NULL)
		ft_strdel(&(node->alias));
	if (node->edges.memory != NULL)
		vec_free(&(node->edges));
}
