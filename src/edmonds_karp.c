/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:11:32 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/13 10:46:19 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	path_init(t_vec *path)
{
	return (vec_new(path, 1, sizeof(long)));
}

static int	bfs(t_vec *network, t_info *info, t_vec *path)
{
	t_queue		queue;
	t_flow_node	*current;
	t_flow_node	*source;
	t_flow_node	*sink;

	(void) path;
	if (queue_init(&queue, sizeof (t_flow_node *)) == ERROR)
		return (ERROR);
	source = hashtable_get_node(network, info->source);
	sink = hashtable_get_node(network, info->sink);
	if (!source || !sink || queue_push(&queue, source) == ERROR)
		return (ERROR);
	while (queue_has_next(&queue))
	{
		current = queue_pop(&queue);
		if (!current)
			return (queue_free(&queue), ERROR);
		if (current == sink)
			return (queue_free(&queue), OK);
		//TODO: Store current node in path
		//TODO: Add current node's children to queue
	}
	return ((vec_free(path), queue_free(&queue)), 0);
}

int	edmonds_karp(t_vec *network, t_info *info, t_vec *paths)
{
	int		flow;
	t_vec	path;

	(void) paths;
	info->max_flow = 0;
	while (TRUE)
	{
		if (path_init(&path) == ERROR)
			return (ERROR);
		flow = bfs(network, info, &path);
		if (flow == 0)
			break ;
		info->max_flow += flow;
		//TODO: iterate through path, set flow for each edge in the path
		//TODO: while iterating through path keep track of which nodes are in paths
		// and which nodes are not
	}
	return (OK);
}
