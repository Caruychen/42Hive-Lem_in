/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:07:07 by cchen             #+#    #+#             */
/*   Updated: 2022/07/27 18:15:54 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	init(uint8_t **marked, t_queue *queue, t_flow_network *network)
{
	size_t	*source;

	source = &network->source;
	*marked = ft_memalloc(sizeof(uint8_t) * network->adj_list.len);
	if (!*marked)
		return (ERROR);
	if (queue_init(queue, sizeof(size_t)) == ERROR)
		return (vec_free(marked), ERROR);
	if (queue_push(queue, source) == ERROR)
	{
		free(*marked);
		return (queue_free(&queue), ERROR);
	}
	(*marked)[*source] = 1;
	return (OK);
}

static int	has_augmenting_path(t_flow_network *network, t_flow_edge **edge_to)
{
	int		*marked;
	t_queue		queue;
	size_t		current;
	t_flow_edge	*edge;
	size_t		index;
	size_t		other;
	
	if (init(&marked, &queue, network->adj_list.len) == ERROR)
		return (ERROR);
	while (queue_has_next(&queue))
	{
		current = *(size_t *)queue_pop(&queue);
		index = 0;
		while (index < network_get(network, current).edges.len)
		{
			edge = node_get(network_get(network, current), index);
			other = edge_other(&edge, current);
			if (edge_has_residual_capacity_to(edge, current, &network->adj_list))
			{
				(*edge_to)[other] = edge;
				marked[other] = TRUE;
				queue_push(&queue, &current);
			}
		}
	}
	return (marked[network->sink]);
}

static int	augment_network(t_flow_network *network, t_flow_edge **edge_to)
{
	size_t		current;
	size_t		source;
	t_flow_edge	*edge;

	source = network->source;
	current = network->sink;
	while (current != source)
	{
		edge = edge_list_get(edge_to, current);
		if (edge_augment_flow_to(edge, current, &network->adj_list) == ERROR)
			return (ERROR);
		current = edge_other(edge, current);
	}
	network_get(network, network->source)->is_free = 1;
	return (OK);
}

static int	edmunds_karp(t_flow_network *network, t_paths *paths)
{
	t_flow_edge	**edge_to;

	edge_to = ft_memalloc(sizeof(*edge_to) * network->adj_list.len);
	while (has_augmenting_path(network, edge_to))
	{
		if (augment_network(network, edge_to) == ERROR)
			return (ERROR);
	}
	ft_memdel(&edge_to);
}

int	solve(t_flow_network *network, t_paths *paths)
{
}
