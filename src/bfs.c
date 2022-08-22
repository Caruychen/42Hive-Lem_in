/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:33:35 by cchen             #+#    #+#             */
/*   Updated: 2022/08/22 12:25:40 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* Initialise and allocate memory for BFS utilities */
int	bfs_init(t_bfs_utils *bfs_utils, t_flow_network *network, int saturate)
{
	size_t	*source;

	source = &network->source;
	bfs_utils->marked = ft_memalloc(sizeof(int) * network->adj_list.len);
	if (!bfs_utils->marked)
		return (ERROR);
	bfs_utils->trace.edge_to = ft_memalloc(sizeof(t_flow_edge *)
			* network->adj_list.len);
	if (!bfs_utils->trace.edge_to)
		return (ERROR);
	if (edge_list_make(&bfs_utils->trace.sink_edges) == ERROR)
		return (ERROR);
	if (queue_init(&bfs_utils->queue, sizeof(size_t)) == ERROR)
		return (ERROR);
	if (queue_push(&bfs_utils->queue, source) == ERROR)
		return (ERROR);
	bfs_utils->saturate_trace = saturate;
	return ((bfs_utils->marked)[*source] = 1, OK);
}

static void bfs_reset_dst_to_start(t_flow_network *network)
{
	size_t	index;

	index = 0;
	while (index < network->adj_list.len)
		network_get(network, index++)->dst_to_start = 0;
}
/* Resets BFS utilities (assigning 0) for next BFS iteration */
int	bfs_reset(t_bfs_utils *bfs_utils, t_flow_network *network)
{
	ft_bzero(bfs_utils->marked, sizeof(int) * network->adj_list.len);
	ft_bzero(bfs_utils->trace.edge_to, sizeof(int) * network->adj_list.len);
	bfs_utils->queue.vec.len = 0;
	bfs_utils->queue.head = 0;
	bfs_utils->queue.tail = 0;
	bfs_utils->trace.sink_edges.len = 0;
	network_get(network, network->source)->path_id = network->source;
	bfs_reset_dst_to_start(network);
	if (queue_push(&bfs_utils->queue, &network->source) == ERROR)
		return (ERROR);
	return ((bfs_utils->marked)[network->source] = 1, OK);
}

/* Frees memory for BFS utilities */
void	bfs_free(t_bfs_utils *bfs_utils)
{
	if (bfs_utils->marked)
		ft_memdel((void **)&bfs_utils->marked);
	if (bfs_utils->trace.edge_to)
		ft_memdel((void **)&bfs_utils->trace.edge_to);
	if (bfs_utils->trace.sink_edges.memory)
		vec_free(&bfs_utils->trace.sink_edges);
	if (bfs_utils->queue.vec.memory)
		queue_free(&bfs_utils->queue);
}
