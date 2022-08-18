/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:50:43 by cchen             #+#    #+#             */
/*   Updated: 2022/08/18 11:22:30 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* The node's dst_to_start is computed and stored in the node 
 * Saves the edge to the edge_to trace
 * Marks the given node as visited
 * Node is enqueued if it is not the end node
 * if END node:
 *   end search if saturace_trace == FALSE
 * else:
 *   Save edge to the sink_edges trace and continue searching
 */
static int	save_edge(t_flow_network *network, t_bfs_utils *bfs_utils,
		size_t to, t_flow_edge *edge)
{
	t_flow_node	*from;

	from = network_get(network, edge_other(edge, to));
	if (!bfs_utils->marked[to] && !bfs_utils->saturate_trace)
		network_get(network, to)->dst_to_start
		= from->dst_to_start + (!edge->flow);
	(bfs_utils->trace.edge_to)[to] = edge;
	bfs_utils->marked[to] = TRUE;
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

/* Loops through each edge in a node's edge bag 
 * Is the node on the other end of the edge is a valid neighbour, and 
 * satisfies a given "condition", then the node is enqueued and the edge
 * is saved to the trace */
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

/* BFS Search incrementally scans each node on the "queue"
 * The Start node is always enqueued first.
 * The node that is being scanned is popped from the queue.
 * If any node linked to the current node by an edge satisifies 
 * a the given "condition" function and is a valid neighbour,
 * the new node is enqueued. 
 *
 * The process continues until:
 * The END node is reached for the first time (IF saturate_trace == FALSE)
 * ALL Nodes are scanned (IF saturate_trace == TRUE)
 * */
int	bfs_search(t_flow_network *network, t_bfs_utils *bfs_utils,
		int (*condition)(t_flow_edge *, const size_t, t_vec *))
{
	bfs_reset(bfs_utils, network);
	while (queue_has_next(&bfs_utils->queue))
		if (scan_next_node(network, bfs_utils, condition))
			break ;
	return (bfs_utils->marked[network->sink]);
}
