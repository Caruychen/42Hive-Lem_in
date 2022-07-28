/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:50:43 by cchen             #+#    #+#             */
/*   Updated: 2022/07/28 13:33:44 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	save_edge(t_flow_network *network, t_bfs_utils *bfs_utils,
		size_t to, t_flow_edge *edge)
{
	(bfs_utils->trace.edge_to)[to] = edge;
	bfs_utils->marked[to] = TRUE;
	if (to != network->sink)
		return (queue_push(&bfs_utils->queue, &to), SEARCH_CONTINUE);
	if (!bfs_utils->saturate_trace)
		return (SEARCH_END);
	return (edge_list_push(&bfs_utils->trace.sink_edges, edge),
		SEARCH_CONTINUE);
}

static int	search_edges(t_flow_network *network, t_bfs_utils *bfs_utils,
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
		edge = node_get(&node, index);
		to = edge_other(edge, current);
		if ((!bfs_utils->marked[to] || to == network->sink)
			&& condition(edge, to, &network->adj_list)
			&& save_edge(network, bfs_utils, to, edge))
			return (SEARCH_END);
		index++;
	}
	return (SEARCH_CONTINUE);
}

int	bfs_search(t_flow_network *network, t_bfs_utils *bfs_utils,
		int (*condition)(t_flow_edge *, const size_t, t_vec *))
{
	bfs_reset(bfs_utils, network);
	while (queue_has_next(&bfs_utils->queue))
	{
		if (search_edges(network, bfs_utils, condition))
			break ;
	}
	return (bfs_utils->marked[network->sink]);
}
