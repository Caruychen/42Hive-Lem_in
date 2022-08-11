/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:50:43 by cchen             #+#    #+#             */
/*   Updated: 2022/08/12 00:41:06 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	save_edge(t_flow_network *network, t_bfs_utils *bfs_utils,
		size_t to, t_flow_edge *edge)
{
	size_t	from;

	from = edge_other(edge, to);
	(bfs_utils->trace.edge_to)[to] = edge;
	bfs_utils->marked[to] = TRUE;
	network_get(network, to)->dst_to_start = network_get(network, from)->dst_to_start + 1;
	if (to != network->sink)
		return (queue_push(&bfs_utils->queue, &to), SEARCH_CONTINUE);
	if (!bfs_utils->saturate_trace)
		return (SEARCH_END);
	return (edge_list_push(&bfs_utils->trace.sink_edges, edge),
		SEARCH_CONTINUE);
}

static int	is_valid_neighbour(size_t to, t_flow_edge edge,
		t_bfs_utils bfs_utils, t_flow_network network)
{
	int	is_backtrack;

	is_backtrack = (edge.flow && edge.from == to && to != network.source);
	return (!bfs_utils.marked[to] || is_backtrack || to == network.sink);
}

static int	scan_next_node(t_flow_network *network, t_bfs_utils *bfs_utils,
		int (*condition)(t_flow_edge *, const size_t, t_vec *))
{
	size_t		current;
	size_t		index;
	size_t		to;
	t_flow_node	node;
	t_flow_edge	*edge;

	current = *(size_t *) queue_pop(&bfs_utils->queue);
	node = *network_get(network, current);
	index = 0;
	while (index < node.edges.len)
	{
		edge = node_get(&node, index++);
		to = edge_other(edge, current);
		if (is_valid_neighbour(to, *edge, *bfs_utils, *network)
			&& condition(edge, to, &network->adj_list)
			&& save_edge(network, bfs_utils, to, edge))
			return (SEARCH_END);
	}
	return (SEARCH_CONTINUE);
}

int	bfs_search(t_flow_network *network, t_bfs_utils *bfs_utils,
		int (*condition)(t_flow_edge *, const size_t, t_vec *))
{
	bfs_reset(bfs_utils, network);
	while (queue_has_next(&bfs_utils->queue))
		if (scan_next_node(network, bfs_utils, condition))
			break ;
	return (bfs_utils->marked[network->sink]);
}
