/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_edge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:49:31 by cchen             #+#    #+#             */
/*   Updated: 2022/06/07 16:05:34 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_flow_edge	*edge_make(int from, int to)
{
	t_flow_edge	*edge;

	edge = (t_flow_edge *) ft_memalloc(sizeof(*edge));
	if (!edge)
		return (NULL);
	edge->from = from;
	edge->to = to;
	return (edge);
}

int	edge_other(t_flow_edge *edge, int node)
{
	if (edge->from == node)
		return (edge->to);
	if (edge->to == node)
		return (edge->from);
	return (ERROR);
}

int	edge_has_residual_capacity_to(t_flow_edge *edge, int node)
{
	if (!edge->flow)
		return (TRUE);
	if (edge->to == node)
		return (FALSE);
	if (edge->from == node)
		return (TRUE);
	return (ERROR);
}

void	edge_set_flow_to(t_flow_edge *edge, int node)
{
	edge->flow = 1;
	if (edge->to != node)
		ft_swap(&(edge->from), &(edge->to));
}

void	edge_unset_flow(t_flow_edge *edge)
{
	edge->flow = 0;
}
