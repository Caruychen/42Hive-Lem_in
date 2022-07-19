/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:11:32 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/19 09:12:38 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edmonds_karp.h"
#include "flow_edge.h"
#include "flow_node.h"
#include "hashtable.h"
#include "lem_in.h"
#include "solve.h"
#include "vec.h"

// Creates an array of the size of n (number of nodes in the graph)
// filled with -1's and a -2 for the source.
static int	path_init(t_vec *network, long source_id, t_vec *path)
{
	size_t	i;

	if (vec_new(path, network->len, sizeof(long)) == ERROR)
		return (ERROR);
	path->len = network->len;
	i = 0;
	while (i < path->len)
	{
		((long *)path->memory)[i] = -1;
		i++;
	}
	((long *)path->memory)[source_id] = -2;
	return (OK);
}

static int	bfs(t_vec *network, t_edm_karp *ek, t_vec *path)
{
	long		current_id;
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
		if (!ft_strcmp(current->alias, ek->sink->alias)) // make this use id
			return (queue_free(&queue), OK);
		i = 0;
		while (i < current->edges.len)
		{
			edge = node_get(current, i);
			if (edge->to != current_id && edge_has_residual_capacity_to(edge, edge->to))
			{
				queue_push(&queue, vec_get(network, edge->to));
				((long *)path->memory)[edge->to] = current_id;
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
	size_t		i;

	current = ek->sink_id;
	ft_putstr(ek->source->alias);
	ft_putstr("->");
	i = 1;
	while (1)
	{
		current = *(long *)vec_get(path, i);
		edge = node_get(vec_get(network, current), 0);
		edge_augment_flow_to(edge, current);
		ft_putstr(((t_flow_node *)vec_get(network, current))->alias);
		if (i == path->len - 1)
			break ;
		ft_putstr("->");
		i++;
		//TODO: reduce capacity of aug path
		//TODO: increase capacity of backward edges
		//TODO: while iterating through path keep track of which nodes are in paths
		// and which nodes are not
	}
	ft_putstr("\n");
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
	t_vec		path;

	edmonds_karp_init(network, info, &ek);
	info->max_flow = 0;
	while (TRUE)
	{
		if (path_init(network, ek.source_id, &path) == ERROR)
			return (ERROR);
		flow = bfs(network, &ek, &path);
		if (flow == 0)
			break ;
		info->max_flow += flow;
		vec_push(&path, &ek.sink_id);
		if (vec_push(paths, &path) == ERROR)
			return (ERROR);
		update_capacities(network, &ek, &path);
	}
	return (OK);
}
