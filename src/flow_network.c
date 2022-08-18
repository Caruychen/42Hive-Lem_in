/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_network.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:36:25 by cchen             #+#    #+#             */
/*   Updated: 2022/08/18 10:57:43 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* Initialises network fields to 0 */
int	network_init(t_flow_network *network)
{
	*network = (t_flow_network){{0}, {0}, 0, 0, 0};
	if (edge_list_make(&(network->edge_list)) == -1)
		return (error(MSG_ERROR_MALLOC));
	if (vec_new(&(network->adj_list), 1, sizeof(t_flow_node)) == ERROR)
		return (edge_list_free(&(network->edge_list)), error(MSG_ERROR_MALLOC));
	return (OK);
}

/* Creates a new node, and adds the node ot the network adjacency list */
int	network_add_node(t_flow_network *network, char *alias, int x, int y)
{
	t_flow_node	node;

	if (node_make(&node, alias, x, y) == ERROR)
		return (ERROR);
	return (vec_push(&(network->adj_list), &node));
}

/* Creates a new edge, and adds the edge to respective nodes at both ends */
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

/* Returns a pointer to the node at given index of the adjacency list */
t_flow_node	*network_get(t_flow_network *network, size_t index)
{
	return ((t_flow_node *) vec_get(&network->adj_list, index));
}

/* Frees memory in the network */
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
