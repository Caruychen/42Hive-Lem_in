/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:50:43 by cchen             #+#    #+#             */
/*   Updated: 2022/07/28 00:22:42 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	save_edge(t_flow_network *network, t_bfs_utils *bfs_utils,
		size_t to, t_flow_edge *edge)
{
	*(bfs_utils->trace.edge_to)[to] = edge;
	bfs_utils->marked[to] = TRUE;
	if (to != network->sink)
		return (queue_push(&bfs_utils->queue, &to), 0);
	if (!bfs_utils->saturate_trace)
		return (TRUE);
	return (edge_list_push(&bfs_utils->trace.sink_edges, edge), FALSE);
}

static int	search_edges(t_flow_network *network, t_bfs_utils *bfs_utils,
		int (*condition)(t_flow_edge *, size_t, t_vec *))
{
	size_t	current;
	size_t	index;
	t_flow_node	node;
	t_flow_edge	*edge;
	size_t	to;

	current = *(size_t *) queue_pop(&bfs_utils->queue);
	node = *network_get(network, current);
	index = 0;
	while (index < node.edge.len)
	{
		edge = node_get(&node, index);
		to = edge_other(edge, current);
		if ((!bfs_utils->marked[to] || to == network->sink)
			&& condition(edge, to, &network->adj_list)
			&& save_edge(network, bfs_utils, to, edge))
			return (TRUE);
		index++;
	}
	return (FALSE);
}

int	search(t_flow_network *network, t_bfs_utils *bfs_utils,
		int (*condition)(t_flow_edge *, size_t, t_vec *))
{
	while (queue_has_next(&bfs_utils.queue))
	{
		if (search_edges(network, &queue, condition, bfs_utils))
			break;
	}
	return (marked[network->sink]);
}
