/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_network_augment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:26:15 by cchen             #+#    #+#             */
/*   Updated: 2022/08/22 12:27:09 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* Uses BFS to determined whether the network has an augmentable path 
 * Returns TRUE or FALSE
 */
int	network_has_augmenting_path(t_flow_network *network, t_bfs_utils *bfs_utils)
{
	bfs_utils->saturate_trace = FALSE;
	return (bfs_search(network, bfs_utils, &edge_has_residual_capacity_to));
}

/* The selected best exit node from select_best_exit is scanned for the 
 * appropriate exit node.
 * */
static void	switch_edge(size_t res, t_trace trace, t_flow_network *network)
{
	size_t		index;
	size_t		target_index;
	t_flow_edge	*edge;
	t_flow_node	*node;
	t_flow_node	*target_node;

	node = network_get(network, res);
	edge = trace.edge_to[res];
	target_node = network_get(network, edge_other(edge, res));
	if (!edge->flow && target_node->dst_to_start == node->dst_to_start - 1)
		return ;
	index = 0;
	while (index < node->edges.len)
	{
		edge = node_get(node, index++);
		target_index = edge_other(edge, res);
		target_node = network_get(network, target_index);
		if (!edge->flow && trace.edge_to[target_index]
			&& target_node->dst_to_start == node->dst_to_start - 1)
		{
			trace.edge_to[res] = edge;
			return ;
		}
	}
}

/* When network_augment encounters a node on a path, determines the best
 * augmentable node from the path. The best node is the one with minimum
 * dst_to_start + dst_to_end. A connection to start node is guaranteed.*/
static void	select_best_exit(t_flow_network *network, size_t index,
	t_trace trace)
{
	size_t		res;
	size_t		min;
	t_flow_edge	*edge;
	t_flow_node	*node;

	edge = trace.edge_to[index];
	min = 0;
	while (edge->flow)
	{
		index = edge_other(edge, index);
		node = network_get(network, index);
		if (!min || min > node->dst_to_start + node->dst_to_end)
		{
			min = node->dst_to_start + node->dst_to_end;
			res = index;
		}
		edge = trace.edge_to[index];
	}
	switch_edge(res, trace, network);
}

/* Augments network with the given trace found by previous bfs search */
int	network_augment(t_flow_network *network, t_trace trace)
{
	size_t		prev;
	size_t		source;
	size_t		index;
	t_flow_edge	*edge;

	prev = 0;
	source = network->source;
	index = network->sink;
	while (index != source)
	{
		edge = trace.edge_to[index];
		if (edge->flow && !prev)
			select_best_exit(network, index, trace);
		prev = edge->flow;
		if (edge_augment_flow_to(edge, index, network) == ERROR)
			return (ERROR);
		index = edge_other(edge, index);
	}
	return (OK);
}
