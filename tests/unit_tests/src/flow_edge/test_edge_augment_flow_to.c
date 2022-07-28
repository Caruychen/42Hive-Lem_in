/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_edge_augment_flow_to.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/07/28 14:20:28 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_edge_augment_flow_to(void)
{
	t_flow_edge	*edge;
	t_flow_network	network;
	t_flow_node	*node1;
	t_flow_node	*node2;
	
	ft_printf("Testing edge_augment_flow_to: ");
	assert(network_init(&network) != ERROR);
	assert(network_add_node(&network, ft_strdup("a"), 1, 0) != ERROR);
	assert(network_add_node(&network, ft_strdup("b"), 1, 1) != ERROR);
	assert(network_add_node(&network, ft_strdup("c"), 1, 2) != ERROR);
	node1 = network_get(&network, 1);
	node2 = network_get(&network, 2);

	edge = edge_make(1, 2);
	assert(network_add_edge(&network, edge) == OK);
	assert(network_add_edge(&network, edge_make(0, 1)) == OK);

	assert(edge->from == 1);
	assert(edge->to == 2);
	assert(edge->flow == 0);

	// Adding forward flow
	assert(edge_augment_flow_to(edge, 2, &network) == OK);
	assert(edge->from == 1);
	assert(edge->to == 2);
	assert(edge->flow == 1);
	assert(node1->is_free == FALSE);
	assert(node2->is_free == TRUE);

	// Reversing flow backward
	assert(edge_augment_flow_to(edge, 1, &network) == OK);
	assert(edge->from == 1);
	assert(edge->to == 2);
	assert(edge->flow == 0);
	assert(node1->is_free == FALSE);
	assert(node2->is_free == FALSE);

	// Adding forward flow twice, result in error
	assert(edge_augment_flow_to(edge, 2, &network) == OK);
	assert(edge_augment_flow_to(edge, 2, &network) == ERROR);
	assert(edge->from == 1);
	assert(edge->to == 2);
	assert(edge->flow == 1);
	assert(node1->is_free == FALSE);
	assert(node2->is_free == FALSE);

	// Reversing flow twice
	assert(edge_augment_flow_to(edge, 1, &network) == OK);
	assert(edge->from == 1);
	assert(edge->to == 2);
	assert(edge->flow == 0);
	assert(node1->is_free == FALSE);
	assert(node2->is_free == FALSE);
	assert(edge_augment_flow_to(edge, 1, &network) == OK);
	assert(edge->from == 2);
	assert(edge->to == 1);
	assert(edge->flow == 1);
	assert(node1->is_free == FALSE);
	assert(node2->is_free == FALSE);

	// reverse flow again, result in error
	node1->is_via_augment = 1;
	node2->is_via_augment = 1;
	assert(edge_augment_flow_to(edge, 1, &network) == ERROR);
	assert(edge->from == 2);
	assert(edge->to == 1);
	assert(edge->flow == 1);
	assert(node1->is_free == FALSE);
	assert(node2->is_free == FALSE);

	assert(edge_augment_flow_to(edge, 2, &network) == OK);
	assert(edge->from == 2);
	assert(edge->to == 1);
	assert(edge->flow == 0);
	assert(node1->is_free == TRUE);
	assert(node2->is_free == FALSE);
	assert(edge_augment_flow_to(edge, 2, &network) == OK);
	assert(edge->from == 1);
	assert(edge->to == 2);
	assert(edge->flow == 1);
	assert(node1->is_free == FALSE);
	assert(node2->is_free == FALSE);

	assert(edge_augment_flow_to(edge, 3, &network) == ERROR);
	assert(edge_augment_flow_to(edge, 0, &network) == ERROR);
	assert(edge_augment_flow_to(edge, -1, &network) == ERROR);

	network_free(&network);
	ft_printf("OK\n");
}
