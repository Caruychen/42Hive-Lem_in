/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:33:35 by cchen             #+#    #+#             */
/*   Updated: 2022/07/27 20:17:50 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	bfs_init(t_bfs_utils *bfs_utils, t_flow_network *network, int saturate)
{
	size_t	*source;

	bfs_utils->marked = ft_memalloc(sizeof(int) * network->adj_list.len);
	if (!bfs_utils->marked)
		return (ERROR);
	bfs_utils->trace.edge_to = ft_memalloc(sizeof(*edge_to) * network->adj_list.len);
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

void	bfs_free(t_bfs_utils *bfs_utils)
{
	if (bfs_utils->marked)
		ft_memdel(&bfs_utils->marked);
	if (bfs_utils->trace.edge_to)
		ft_memdel(&bfs_utils->trace.edge_to);
	if (bfs_utils->trace.sink_edges.memory)
		vec_free(&bfs_utils->trace.sink_edges);
	if (bfs_utils->queue.vec.memory)
		queue_free(&bfs_utils->queue);
}
