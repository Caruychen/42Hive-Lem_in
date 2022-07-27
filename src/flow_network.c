/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_network.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:36:25 by cchen             #+#    #+#             */
/*   Updated: 2022/07/27 15:44:09 by cchen            ###   ########.fr       */
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
	*network = (t_flow_network){0};
	if (edge_list_make(&(network->edge_list)) == -1)
		return (ERROR);
	return (vec_new(&(network->adj_list), 1, sizeof(t_flow_node)));
}

int	network_add_node(t_flow_network *network, char *alias, int x, int y)
{
	t_flow_node	node;

	if (node_make(&node, alias, x, y) == ERROR)
		return (ERROR);
	return (vec_push(&(network->adj_list), &node));
}

int	network_add_edge(t_flow_network *network, t_flow_edge *edge)
{
	t_vec	*adj_list;

	adj_list = &(network->adj_list);
	if (node_push((t_flow_node *)vec_get(adj_list, edge->from), edge) == ERROR)
		return (ERROR);
	if (node_push((t_flow_node *)vec_get(adj_list, edge->to), edge) == ERROR)
		return (ERROR);
	if (edge_list_push(&(network->edge_list), edge) == ERROR)
		return (ERROR);
	return (OK);
}

t_flow_node	*network_get(t_flow_network *network, size_t index)
{
	return ((t_flow_node *) vec_get(&network->adj_list, index));
}

void	network_free(t_flow_network *network)
{
	size_t	index;
	t_vec	*adj_list;

	edge_list_free(&(network->edge_list));
	adj_list = &(network->adj_list);
	index = 0;
	while (index < adj_list->len)
		node_free(&(adj_list->memory[adj_list->elem_size * index++]));
	vec_free(adj_list);
}
