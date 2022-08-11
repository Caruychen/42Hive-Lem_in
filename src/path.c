/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:00:39 by cchen             #+#    #+#             */
/*   Updated: 2022/08/12 00:44:33 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int	path_new(t_path *path)
{
	path->ants = 0;
	path->height = 0;
	if (vec_new(&path->nodes, 1, sizeof(t_flow_node *)) == ERROR)
		return (ERROR);
	return (OK);
}

int	path_fill(t_path *path, size_t index, t_trace trace,
		t_flow_network *network)
{
	t_flow_edge	*edge;
	t_flow_node	*node;
	size_t		dst_to_end;

	if (!path || !trace.edge_to || !trace.sink_edges.memory)
		return (ERROR);
	edge = edge_list_get(&trace.sink_edges, index);
	dst_to_end = 0;
	while (edge)
	{
		node = network_get(network, edge->to);
		node->dst_to_end = dst_to_end++;
		if (vec_push(&path->nodes, node) == ERROR)
			return (ERROR);
		edge = trace.edge_to[edge->from];
	}
	path->height = path->nodes.len;
	return (OK);
}

t_flow_node	*path_get(t_path *path, size_t index)
{
	return ((t_flow_node *) vec_get(&path->nodes, index));
}

void	path_free(t_path *path)
{
	path->ants = 0;
	path->height = 0;
	vec_free(&path->nodes);
}
