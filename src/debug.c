/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:12 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/19 15:29:31 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	debug_parent_array_print(t_vec *path, t_vec *network, long sink_id)
{
	long	node_id;

	ft_putendl("Path found (from sink to source):");
	node_id = sink_id;
	while (1)
	{
		ft_printf("%i", node_id);
		ft_printf("(%s)", ((t_flow_node *)vec_get(network, node_id))->alias);
		ft_putchar(' ');
		node_id = ((long *)path->memory)[node_id];
		if (node_id < 0 || (size_t) node_id > network->len)
			break ;
		ft_printf("-> ");
	}
	ft_putchar('\n');
}

