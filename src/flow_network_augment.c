/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_network_augment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:26:15 by cchen             #+#    #+#             */
/*   Updated: 2022/08/02 12:07:56 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	network_has_augmenting_path(t_flow_network *network, t_bfs_utils *bfs_utils)
{
	bfs_utils->saturate_trace = FALSE;
	return (bfs_search(network, bfs_utils, &edge_has_residual_capacity_to));
}

int	network_augment(t_flow_network *network, t_trace trace)
{
	size_t		source;
	size_t		index;
	t_flow_edge	*edge;

	source = network->source;
	index = network->sink;
	while (index != source)
	{
		edge = trace.edge_to[index];
		if (edge_augment_flow_to(edge, index, network) == ERROR)
			return (ERROR);
		index = edge_other(edge, index);
	}
	return (OK);
}
