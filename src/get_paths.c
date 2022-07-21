/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:24:09 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/21 12:09:02 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flow_edge.h"
#include "lem_in.h"
#include "queue.h"
#include "vec.h"

typedef struct s_bfs
{
	t_queue	queue;
	t_vec	parent_array;
	long	current;
	long	other;
}	t_bfs;

static int	bfs_enqueue_children(t_vec *network, t_bfs *bfs, t_info *info)
{
	size_t		i;
	t_flow_node	*node;
	t_flow_edge	*edge;

	node = vec_get(network, bfs->current);
	i = 0;
	while (i < node->edges.len)
	{
		edge = edge_list_get(&node->edges, i);
		if (!edge)
			return (ERROR);
		bfs->other = edge_other(edge, bfs->current);
		if (has_no_parent(&bfs->parent_array, bfs->other)
			&& edge_has_residual_capacity_to(edge, bfs->other))
		{
			if (queue_push(&bfs->queue, vec_get(network, bfs->other)) == ERROR)
				return (ERROR);
			parent_array_update(&bfs->parent_array, bfs->other, bfs->current);
			/* if (bfs->other == info->sink_id) */
			/* 	bfs->sink_parents; */
		}
		i++;
	}
	return (OK);
}

static int	get_paths_bfs(t_vec *network, t_info *info)
{
	t_bfs	bfs;

	if (queue_init(&bfs.queue, sizeof (long)) == ERROR)
		return (ERROR);
	if (queue_push(&bfs.queue, &info->source_id) == ERROR)
		return (queue_free(&bfs.queue), ERROR);
	while (queue_has_next(&bfs.queue))
	{
		bfs.current = *(long *)queue_pop(&bfs.queue);
		if (bfs_enqueue_children(network, &bfs, info) == ERROR)
			return (queue_free(&bfs.queue), ERROR);
	}
	return (OK);
}

int	get_paths(t_vec *network, t_info *info, t_vec *paths)
{
	t_vec	path;
	t_vec	parent_array;

	if (vec_new(&parent_array, network->len, sizeof(long)) == ERROR)
		return (ERROR);
	if (get_paths_bfs(network, info))
		return (vec_free(&parent_array), ERROR);
	if (vec_new(&path, 1, sizeof (long)) == ERROR)
		return (vec_free(&parent_array), ERROR);
	if (vec_push(paths, &path) == ERROR)
		return (vec_free(&parent_array), ERROR);
	return (vec_free(&parent_array), OK);
}
