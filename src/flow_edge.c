/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_edge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:49:31 by cchen             #+#    #+#             */
/*   Updated: 2022/07/26 00:26:58 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *   Flow edge represents the link/tunnel between nodes (i.e. rooms).
 *   Edge capacity is capped at 1, making the "flow" state also a
 *   binary state. The flow state is used for the edmunds-karp algorithm.
 *
 *   The flow edge data type:
 *    ------------------
 *   | FROM | TO | FLOW |
 *    ------------------
 * 
 *   Where FROM and TO describe the INDEX of the respective nodes at
 *   both ends. The nodes are part of an indexed array implemented in the
 *   flow_network data type.
 *
 *   NOTE: How we interpret the FLOW as a binary state, is crucial to how
 *   path augmentation is implemented for the edmunds-karp algorithm.
 *   When FLOW = 0:
 *       * There is residual flow available for other direction
 *       * The residual flow is bi-directional
 *       * The directionality of FROM & TO are ignored
 *   When FLOW = 1:
 *       * Residual flow is only available in the direction towards FROM
 *       * The residual flow is directional
 *       * Directionality is embedded into FROM & TO
*/

#include <stdint.h>
#include "lem_in.h"

t_flow_edge	*edge_make(const long from, const long to)
{
	t_flow_edge	*edge;

	if (from < 0 || to < 0)
		return (NULL);
	edge = (t_flow_edge *) ft_memalloc(sizeof(*edge));
	if (!edge)
		return (NULL);
	edge->from = from;
	edge->to = to;
	return (edge);
}

long	edge_other(t_flow_edge *edge, const long node)
{
	if (edge->from == node)
		return (edge->to);
	if (edge->to == node)
		return (edge->from);
	return (ERROR);
}

int	edge_has_residual_capacity_to(t_flow_edge *edge, const long to,
		t_flow_network *network)
{
	t_flow_node	*origin;
	t_flow_node	*dst;

	origin = network_get(network, edge_other(edge, to));
	dst = network_get(network, to);
	if ((edge->from != to && edge->to != to) || !origin || !dst)
		return (ERROR);
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

int	edge_augment_flow_to(t_flow_edge *edge, const long to,
		t_flow_network *network)
{
	t_flow_node	*origin;

	origin = network_get(network, edge_other(edge, to));
	if (edge->from != to && edge->to != to)
		return (ERROR);
	if (edge->flow && edge->to == to)
		return (ERROR);
	if (!edge->flow && edge->to != to)
		ft_swap_l(&(edge->from), &(edge->to));
	origin->is_free = (edge->flow && origin->is_via_augment);
	edge->flow = ~edge->flow;
	return (OK);
}

void	edge_free(t_flow_edge **edge)
{
	free(*edge);
	*edge = NULL;
}
