/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:00:39 by cchen             #+#    #+#             */
/*   Updated: 2022/08/01 16:56:22 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	path_fill(t_path *path, size_t index, t_trace trace)
{
	t_flow_edge	*edge;

	if (!path || !trace.edge_to || !trace.sink_edges.memory)
		return (ERROR);
	edge = edge_list_get(&trace.sink_edges, index);
	if (!edge)
		return (ERROR);
	while (edge)
	{
		if (vec_push(&path->nodes, &edge->to) == ERROR)
			return (ERROR);
		edge = trace.edge_to[edge->from];
	}
	return (OK);
}
