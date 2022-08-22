/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:50:43 by cchen             #+#    #+#             */
/*   Updated: 2022/08/21 22:36:07 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	memoize_search_history(size_t to, t_flow_edge *edge,
		t_flow_network *network, t_bfs_utils *bfs_utils)
{
	t_flow_node	*from;
	t_flow_node	*dst;

	from = network_get(network, edge_other(edge, to));
	dst = network_get(network, to);
	if (!bfs_utils->marked[to] && !bfs_utils->saturate_trace)
		dst->dst_to_start = from->dst_to_start + (!edge->flow);
	if (dst->is_free)
	{
		dst->path_id = from->path_id;
		dst->dst_to_end = from->dst_to_end;
	}
}

/*
 * Updates edge_to array and marks to node as visited.
 * Memoizes bfs traversal history in visited node.
 * Enqueues node if it is not the end node.
*/
static int	save_edge(t_flow_network *network, t_bfs_utils *bfs_utils,
		size_t to, t_flow_edge *edge)
{
	memoize_search_history(to, edge, network, bfs_utils);
	(bfs_utils->trace.edge_to)[to] = edge;
	bfs_utils->marked[to] = TRUE;
	if (to != network->sink)
		return (queue_push(&bfs_utils->queue, &to), SEARCH_CONTINUE);
	if (!bfs_utils->saturate_trace)
		return (SEARCH_END);
	return (edge_list_push(&bfs_utils->trace.sink_edges, edge),
		SEARCH_CONTINUE);
}

/* Valid neighbour: unvisited, is backtracking, is shortcut, sink node */
static int	is_valid_neighbour(size_t to, t_flow_edge edge,
		t_bfs_utils bfs_utils, t_flow_network network)
{
	int			is_backtrack;
	int			is_shortcut;
	t_flow_node	*origin;
	t_flow_node	*dst;

	dst = network_get(&network, to);
	origin = network_get(&network, edge_other(&edge, to));
	is_backtrack = (edge.flow && edge.from == to && to != network.source);
	is_shortcut = (dst->is_free
			&& dst->path_id == origin->path_id
			&& dst->dst_to_start == origin->dst_to_start + 1
			&& dst->dst_to_end < origin->dst_to_end);
	return (!bfs_utils.marked[to] || is_backtrack || is_shortcut
		|| to == network.sink);
}

/* Pops next node off the queue, and tests its edges against given condition */
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

/*
 * BFS Search
 * This BFS sub-function is made to perform basic network searching. Able to
 * perform two types of search.
 *
 * 1. Single path search (Terminates at first time end node is reached)
 * 2. Multi path search (Terminates after all nodes scanned. Saturates trace)
 *
 * Incrementally pops nodes off the queue, and scan's the node's respective
 * edges. Nodes that satisfy a given condition are enqueued, and the
 * corresponding edge is saved to the edge_to & sink_edges trace.
 */
int	bfs_search(t_flow_network *network, t_bfs_utils *bfs_utils,
		int (*condition)(t_flow_edge *, const size_t, t_vec *))
{
	bfs_reset(bfs_utils, network);
	while (queue_has_next(&bfs_utils->queue))
		if (scan_next_node(network, bfs_utils, condition))
			break ;
	return (bfs_utils->marked[network->sink]);
}
