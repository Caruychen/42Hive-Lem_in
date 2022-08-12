/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_network_augment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:26:15 by cchen             #+#    #+#             */
/*   Updated: 2022/08/12 10:07:57 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	network_has_augmenting_path(t_flow_network *network, t_bfs_utils *bfs_utils)
{
	bfs_utils->saturate_trace = FALSE;
	return (bfs_search(network, bfs_utils, &edge_has_residual_capacity_to));
}

static void	switch_edge(size_t res, t_trace trace, t_flow_network *network)
{
	t_flow_edge	*edge;
	size_t		index;
	t_flow_node	*node;
	t_flow_node	*target_node;

	edge = trace.edge_to[res];
	if (!edge->flow)
		return ;
	node = network_get(network, res);
	index = 0;
	while (index < node->edges.len)
	{
		edge = node_get(node, index++);
		target_node = network_get(network, edge_other(edge, res));
		if (!edge->flow && target_node->dst_to_start == node->dst_to_start - 1)
		{
			trace.edge_to[res] = edge;
			return ;
		}
	}
}

static size_t	select_exit(t_flow_network *network, size_t index,
	t_trace trace)
{
	size_t		res;
	size_t		tmp;
	size_t		min;
	t_flow_edge	*edge;
	t_flow_node	*node;

	edge = trace.edge_to[index];
	tmp = edge_other(edge, index);
	node = network_get(network, tmp);
	min = node->dst_to_start + node->dst_to_end;
	res = tmp;
	edge = trace.edge_to[tmp];
	while (edge->flow)
	{
		tmp = edge_other(edge, tmp);
		node = network_get(network, tmp);
		if (min >= node->dst_to_start + node->dst_to_end)
		{
			min = node->dst_to_start + node->dst_to_end;
			res = tmp;
		}
		edge = trace.edge_to[tmp];
	}
	switch_edge(res, trace, network);
	return (res);
}

int	network_augment(t_flow_network *network, t_trace trace)
{
	size_t		source;
	size_t		index;
	t_flow_edge	*edge;

	source = network->source;
	index = network->sink;
	while (index != source)
	{
		edge = trace.edge_to[index];
		if (edge->flow)
			select_exit(network, index, trace);
		if (edge_augment_flow_to(edge, index, network) == ERROR)
			return (ERROR);
		index = edge_other(edge, index);
	}
	return (OK);
}
