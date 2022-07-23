/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_network.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:36:25 by cchen             #+#    #+#             */
/*   Updated: 2022/07/23 10:58:43 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *   Flow Network is an adjacency list implementation, representing the whole
 *   ant nest graph.
 *   
 *   It is simply implemented as a vector (dynamic array), with each element
 *   being a node of the rooms. The rooms are numbered according to their index
 *   in the vector, and are thus implicitly numbered by insertion order.
 *  
 *   The t_vec data type is sufficient to represent the flow network graph.
 *   data structure looks a bit like this:
 * 
 *   index   --------------
 *     0    | ALIAS, EDGES | <-- DATA TYPE: flow_node
 *           --------------        -------------------------
 *     1    | ALIAS, EDGES | ---> | FROM: 1, TO: 2, FLOW: 0 |
 *           --------------        -----------------------------
 *     2    | ALIAS, EDGES | ---> | 2, 5, 0 | 2, N, 1 | 1, 2, 0 | 
 *           --------------        -----------------------------
 *                ..                   ^---------v-------------------
 *           --------------        ------------------------         |
 *     5    | ALIAS, EDGES | ---> | 5, 9, 0 | 2, 5, 0 | ... |       |
 *           --------------        ------------------------         |
 *                ...                                               |
 *           --------------        ---------------                  |
 *     N    | ALIAS, EDGES | ---> | 2, N, 1 | ... |                 |
 *           --------------        ---------------                  |
 *                                                                  |
 *                                       Edges between rooms have duplicates
 *                                       between corresponding rooms. 
 *                                       both point to the same edge object,
 *                                       so are NOT copies.
*/

#include "lem_in.h"

int	network_init(t_flow_network *network)
{
	if (edge_list_make(&(network->edge_list)) == -1)
		return (ERROR);
	return (vec_new(&(network->network), 1, sizeof(t_flow_node)));
}

int	network_add_node(t_flow_network *network, char *alias, int x, int y)
{
	t_flow_node	node;

	if (node_make(&node, alias, x, y) == ERROR)
		return (ERROR);
	return (vec_push(&(network->network), &node));
}

int	network_add_edge(t_flow_network *network, t_flow_edge *edge)
{
	if (node_push((t_flow_node *)vec_get(network, edge->from), edge) == ERROR)
		return (ERROR);
	if (node_push((t_flow_node *)vec_get(network, edge->to), edge) == ERROR)
		return (ERROR);
	if (edge_list_push(&(network->edge_list), edge) == ERROR)
		return (ERROR);
	return (OK);
}

void	network_free(t_flow_network *network)
{
	size_t	index;

	edge_list_free(&(network->edge_list));
	index = 0;
	while (index < network->len)
		node_free(&(network->memory[network->elem_size * index++]));
	vec_free(network);
}
