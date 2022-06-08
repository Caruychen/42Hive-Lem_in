/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_network.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:36:25 by cchen             #+#    #+#             */
/*   Updated: 2022/06/08 15:32:50 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	network_init(t_vec *network)
{
	return (vec_new(network, 1, sizeof(t_flow_node)));
}

int	network_add_node(t_vec *network, char *alias)
{
	t_flow_node	node;

	node = node_make(alias);
	if (!node.edges.memory)
		return (ERROR);
	return (vec_push(network, &node));
}

int	network_add_edge(t_vec *network, t_flow_edge *edge)
{
	if (node_add_edge((t_flow_node *)vec_get(network, edge->from), edge) == ERROR)
		return (ERROR);
	if (node_add_edge((t_flow_node *)vec_get(network, edge->to), edge) == ERROR)
		return (ERROR);
	return (OK);
}

void	network_free(t_vec *network)
{
	// Free all nodes then network itself

	vec_free(network);
}
