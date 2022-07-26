/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_edge_has_residual_capacity_to.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:53:42 by cchen             #+#    #+#             */
/*   Updated: 2022/07/26 11:44:30 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_edge_has_residual_capacity_to(void)
{
	t_flow_edge	*edge02;
	t_flow_edge	*edge21;
	t_flow_edge	*edge22;
	t_flow_edge	*edge32;
	t_flow_edge	*edge24;
	
	t_flow_network	network;

	ft_printf("Testing edge_has_residual_capacity_to: ");
	assert(network_init(&network) != ERROR);
	assert(network_add_node(&network, ft_strdup("a"), 1, 0) != ERROR);
	assert(network_add_node(&network, ft_strdup("b"), 1, 1) != ERROR);
	assert(network_add_node(&network, ft_strdup("c"), 1, 2) != ERROR);
	assert(network_add_node(&network, ft_strdup("d"), 1, 3) != ERROR);
	assert(network_add_node(&network, ft_strdup("e"), 1, 4) != ERROR);
	network_get(&network, 0)->is_free = 0;
	network_get(&network, 1)->is_free = 0;
	network_get(&network, 2)->is_free = 0;

	edge02 = edge_make(0, 2);
	edge21 = edge_make(2, 1);
	edge22 = edge_make(2, 2);
	edge32 = edge_make(3, 2);
	edge24 = edge_make(2, 4);
	edge02->flow = 1;
	edge21->flow = 1;
	assert(network_add_edge(&network, edge02) == OK);
	assert(network_add_edge(&network, edge21) == OK);
	assert(network_add_edge(&network, edge22) == OK);
	assert(network_add_edge(&network, edge32) == OK);
	assert(network_add_edge(&network, edge24) == OK);

	assert(edge_has_residual_capacity_to(edge32, 3, &network) == FALSE);
	assert(edge_has_residual_capacity_to(edge24, 4, &network) == FALSE);
	assert(edge_has_residual_capacity_to(edge02, 0, &network) == TRUE);
	assert(edge_has_residual_capacity_to(edge21, 1, &network) == FALSE);
	assert(edge_has_residual_capacity_to(edge22, 2, &network) == FALSE);
	assert(network_get(&network, 0)->is_via_augment == TRUE);

	network_get(&network, 2)->is_via_augment = TRUE;
	assert(edge_has_residual_capacity_to(edge32, 3, &network) == TRUE);
	assert(edge_has_residual_capacity_to(edge24, 4, &network) == TRUE);
	assert(edge_has_residual_capacity_to(edge02, 0, &network) == TRUE);
	assert(edge_has_residual_capacity_to(edge21, 1, &network) == FALSE);
	assert(edge_has_residual_capacity_to(edge22, 2, &network) == FALSE);
	assert(network_get(&network, 3)->is_via_augment == FALSE);
	assert(network_get(&network, 4)->is_via_augment == FALSE);
	assert(network_get(&network, 0)->is_via_augment == TRUE);

	assert(edge_has_residual_capacity_to(edge32, 2, &network) == TRUE);
	assert(edge_has_residual_capacity_to(edge24, 2, &network) == TRUE);
	assert(edge_has_residual_capacity_to(edge02, 2, &network) == FALSE);
	assert(edge_has_residual_capacity_to(edge21, 2, &network) == TRUE);

	assert(edge_has_residual_capacity_to(edge24, 5, &network) == ERROR);

	network_free(&network);
	ft_printf("OK\n");
}
