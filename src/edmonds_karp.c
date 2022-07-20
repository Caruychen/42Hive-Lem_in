/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:11:32 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/20 15:10:16 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	enqueue_children(t_vec *network, t_edm_karp *ek, t_queue *queue)
{
	size_t		i;
	t_flow_edge	*edge;

	i = 0;
	while (i < ek->current->edges.len)
	{
		edge = node_get(ek->current, i);
		if (!edge)
			return (ERROR);
		ek->other_id = edge_other(edge, ek->current_id);
		if (has_no_parent(&ek->parent_array, ek->other_id)
			&& edge_has_residual_capacity_to(edge, ek->other_id))
		{
			if (queue_push(queue, vec_get(network, ek->other_id)) == ERROR)
				return (ERROR);
			parent_array_update(&ek->parent_array, ek->other_id, ek->current_id);
			if (ek->other_id == ek->sink_id)
				return (ek->path_found = TRUE, OK);
		}
		i++;
	}
	return (OK);
}

static int	bfs(t_vec *network, t_edm_karp *ek)
{
	t_queue		queue;

	ek->path_found = FALSE;
	if (queue_init(&queue, sizeof (t_flow_node)) == ERROR)
		return (ERROR);
	if (queue_push(&queue, ek->source) == ERROR)
		return (queue_free(&queue), ERROR);
	while (queue_has_next(&queue))
	{
		ek->current = queue_pop(&queue);
		ek->current_id = hashtable_get_node_index(network, ek->current->alias);
		if (!ek->current)
			return (queue_free(&queue), ERROR);
		if (enqueue_children(network, ek, &queue) == ERROR)
			return (ERROR);
		if (ek->path_found == TRUE)
			return (queue_free(&queue), OK);
	}
	return ((vec_free(&ek->parent_array), queue_free(&queue)), 0);
}

static int	update_capacities(t_vec *network, t_edm_karp *ek)
{
	t_flow_edge	*edge;
	long		current;
	long		parent;

	current = ek->sink_id;
	while (1)
	{
		parent = *(long *)vec_get(&ek->parent_array, current);
		edge = node_get_edge_between(vec_get(network, parent), current);
		if (!edge)
			return (error(MSG_ERR_NULL_EDGE));
		if (edge_augment_flow_to(edge, current) == ERROR)
			return (error(MSG_ERR_AUG_FLOW));
		if (parent == ek->source_id)
			break ;
		current = parent;
	}
	return (OK);
}

static int	edmonds_karp_init(t_vec *network, t_info *info, t_edm_karp *ek)
{
	info->max_flow = 0;
	if (vec_new(&ek->parent_array, network->len, sizeof(long)) == ERROR)
		return (ERROR);
	ek->source_id = hashtable_get_node_index(network, info->source);
	ek->sink_id = hashtable_get_node_index(network, info->sink);
	ek->source = hashtable_get_node(network, info->source);
	ek->sink = hashtable_get_node(network, info->sink);
	return (OK);
}

int	edmonds_karp(t_vec *network, t_info *info, t_vec *paths)
{
	t_edm_karp	ek;
	int			flow;
	t_vec		path;

	edmonds_karp_init(network, info, &ek);
	while (TRUE)
	{
		if (parent_array_reset(network, ek.source_id, &ek.parent_array) == ERROR)
			return (vec_free(&ek.parent_array), ERROR);
		flow = bfs(network, &ek);
		if (flow == 0)
			break ;
		info->max_flow += flow;
		debug_parent_array_print(&ek.parent_array, network, ek.sink_id);
		if (update_capacities(network, &ek) == ERROR)
			return (vec_free(&ek.parent_array), ERROR);
		if (vec_new(&path, 1, sizeof (long)) == ERROR)
			return (vec_free(&ek.parent_array), ERROR);
		if (parent_array_get_path(&ek.parent_array, &path, ek.sink_id) == ERROR)
			return (vec_free(&ek.parent_array), ERROR);
		if (vec_push(paths, &path) == ERROR)
			return (vec_free(&ek.parent_array), ERROR);
	}
	return (vec_free(&ek.parent_array), OK);
}
