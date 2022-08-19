/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:00:39 by cchen             #+#    #+#             */
/*   Updated: 2022/08/19 16:20:45 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* Allocates memory for, and creates a new path */
int	path_new(t_path *path)
{
	path->ants = 0;
	path->height = 0;
	if (vec_new(&path->nodes, 1, sizeof(t_flow_node *)) == ERROR)
		return (ERROR);
	return (OK);
}

/* Fills path with nodes found in the edge_to trace. Simultaneously computes
 * the node's corresonding dst_to_end node */
int	path_fill(t_path *path, size_t index, t_trace trace,
		t_flow_network *network)
{
	t_flow_edge	*edge;
	t_flow_node	*node;
	t_flow_node	*from;
	size_t		dst_to_end;

	if (!path || !trace.edge_to || !trace.sink_edges.memory)
		return (ERROR);
	edge = edge_list_get(&trace.sink_edges, index);
	dst_to_end = 0;
	while (edge)
	{
		node = network_get(network, edge->to);
		node->dst_to_end = dst_to_end++;
		from = network_get(network, edge->from);
		from->path_id = edge->from * (edge->to == network->sink)
			+ node->path_id * (edge->to != network->sink);
		if (vec_push(&path->nodes, &node) == ERROR)
			return (ERROR);
		edge = trace.edge_to[edge->from];
	}
	path->height = path->nodes.len;
	return (OK);
}

/* Returns a pointer to the node corresponding to the given index of a path */
t_flow_node	*path_get(t_path *path, size_t index)
{
	t_flow_node	**node;

	node = vec_get(&path->nodes, index);
	return (*node);
}

/* Frees a path's memory */
void	path_free(t_path *path)
{
	path->ants = 0;
	path->height = 0;
	vec_free(&path->nodes);
}
