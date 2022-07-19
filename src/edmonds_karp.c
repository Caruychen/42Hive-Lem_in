/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:11:32 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/19 16:55:10 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	bfs(t_vec *network, t_edm_karp *ek, t_vec *path)
{
	long		current_id;
	long		other_id;
	t_flow_node	*current;
	t_flow_edge	*edge;
	t_queue		queue;
	size_t		i;

	if (queue_init(&queue, sizeof (t_flow_node)) == ERROR)
		return (ERROR);
	if (queue_push(&queue, ek->source) == ERROR)
		return (ERROR);
	while (queue_has_next(&queue))
	{
		current = queue_pop(&queue);
		current_id = hashtable_get_node_index(network, current->alias);
		if (!current)
			return (queue_free(&queue), ERROR);
		i = 0;
		while (i < current->edges.len)
		{
			edge = node_get(current, i);
			other_id = edge_other(edge, current_id);
			if (has_no_parent(path, other_id) && edge_has_residual_capacity_to(edge, other_id))
			{
				queue_push(&queue, vec_get(network, other_id));
				parent_array_update(path, other_id, current_id);
				if (other_id == ek->sink_id)
					return (queue_free(&queue), OK);
			}
			i++;
		}
	}
	return ((vec_free(path), queue_free(&queue)), 0);
}

static int	update_capacities(t_vec *network, t_edm_karp *ek, t_vec *path)
{
	t_flow_edge	*edge;
	long		current;
	long		parent;

	current = ek->sink_id;
	while (1)
	{
		parent = *(long *)vec_get(path, current);
		edge = node_get_edge_between(vec_get(network, parent), current);
		edge_augment_flow_to(edge, current);
		if (parent == ek->source_id)
			break ;
		current = parent;
	}
	return (OK);
}

static int	edmonds_karp_init(t_vec *network, t_info *info, t_edm_karp *ek)
{
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
	t_vec		parent_array;

	edmonds_karp_init(network, info, &ek);
	info->max_flow = 0;
	while (TRUE)
	{
		if (parent_array_init(network, ek.source_id, &parent_array) == ERROR)
			return (ERROR);
		flow = bfs(network, &ek, &parent_array);
		if (flow == 0)
			break ;
		info->max_flow += flow;
		debug_parent_array_print(&parent_array, network, ek.sink_id);
		if (vec_push(paths, &parent_array) == ERROR)
			return (ERROR);
		update_capacities(network, &ek, &parent_array);
	}
	return (OK);
}
