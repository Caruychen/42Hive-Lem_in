/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:00:39 by cchen             #+#    #+#             */
/*   Updated: 2022/08/02 16:38:52 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

	if (!path || !trace.edge_to || !trace.sink_edges.memory)
		return (ERROR);
	edge = edge_list_get(&trace.sink_edges, index);
	while (edge)
	{
		if (vec_push(&path->nodes, network_get(network, edge->to)) == ERROR)
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
