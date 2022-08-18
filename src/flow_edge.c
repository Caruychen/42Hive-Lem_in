/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_edge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:49:31 by cchen             #+#    #+#             */
/*   Updated: 2022/08/18 10:55:51 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "lem_in.h"

/* Allocates memory for, and creates a new edge */
t_flow_edge	*edge_make(const long from, const long to)
{
	t_flow_edge	*edge;

	if (from < 0 || to < 0)
		return (NULL);
	edge = (t_flow_edge *) ft_memalloc(sizeof(*edge));
	if (!edge)
		return (NULL);
	edge->from = (size_t) from;
	edge->to = (size_t) to;
	return (edge);
}

/* Returns the value at the "other" end of the edge to the given node */
long	edge_other(t_flow_edge *edge, const size_t node)
{
	if (edge->from == node)
		return (edge->to);
	if (edge->to == node)
		return (edge->from);
	return (ERROR);
}

/* Returns whether the given edge has residual capacity to specified node */
int	edge_has_residual_capacity_to(t_flow_edge *edge, const size_t to,
		t_vec *adj_list)
{
	t_flow_node	*origin;
	t_flow_node	*dst;

	origin = (t_flow_node *) vec_get(adj_list, edge_other(edge, to));
	dst = (t_flow_node *) vec_get(adj_list, to);
	if ((edge->from != to && edge->to != to) || !origin || !dst)
		return (ERROR);
	if (edge->from == edge->to)
		return (FALSE);
	if (!edge->flow)
	{
		if (origin->is_free || origin->is_via_augment)
			return (dst->is_via_augment = 0, TRUE);
		return (FALSE);
	}
	if (edge->to == to)
		return (FALSE);
	if (edge->from == to)
		return (dst->is_via_augment = 1, TRUE);
	return (ERROR);
}

/* Returns whether the edge has flow towards the given node */
int	edge_has_flow_to(t_flow_edge *edge, const size_t to, t_vec *adj_list)
{
	(void) adj_list;
	if ((edge->from != to && edge->to != to))
		return (ERROR);
	return (edge->flow && edge->to == to);
}

/* Augments flow to a given node 
 * If FLOW == 0, adds flow, and ensures the TO & FROM fields have correct values
 *  -> edge.to = to
 *  -> edge.from = edge_other(edge, to);
 *
 * If FLOW == 1, sets FLOW = 0
 *
 * Determines whether the origin node (edge_other(edge, to)) is freed or not.
 * */
int	edge_augment_flow_to(t_flow_edge *edge, const size_t to,
		t_flow_network *network)
{
	t_flow_node	*origin;
	size_t		origin_id;

	origin_id = edge_other(edge, to);
	origin = network_get(network, origin_id);
	if (edge->from != to && edge->to != to)
		return (ERROR);
	if (edge->flow && edge->to == to)
		return (ERROR);
	if (!edge->flow && edge->to != to)
		ft_swap_ul(&(edge->from), &(edge->to));
	origin->is_free = ((edge->flow && origin->is_via_augment)
			|| origin_id == network->source);
	edge->flow = ~edge->flow;
	return (OK);
}
