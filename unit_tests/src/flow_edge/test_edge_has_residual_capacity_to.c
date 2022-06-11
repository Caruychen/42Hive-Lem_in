/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_edge_has_residual_capacity_to.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:53:42 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 14:22:24 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_edge_has_residual_capacity_to(void)
{
	t_flow_edge	*edge;

	ft_printf("Testing edge_has_residual_capacity_to: ");
	edge = edge_make(1, 2);
	assert(edge_has_residual_capacity_to(edge, 1));
	assert(edge_has_residual_capacity_to(edge, 2));
	assert(edge_has_residual_capacity_to(edge, 0) == ERROR);

	edge->flow = 1;
	assert(edge_has_residual_capacity_to(edge, 1) == TRUE);
	assert(edge_has_residual_capacity_to(edge, 2) == FALSE);

	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(0, 0);
	assert(edge_has_residual_capacity_to(edge, 0) == TRUE);
	edge->flow = 1;
	assert(edge_has_residual_capacity_to(edge, 0) == FALSE);

	edge_free(&edge);
	assert(edge == NULL);

	ft_printf("OK\n");
}
