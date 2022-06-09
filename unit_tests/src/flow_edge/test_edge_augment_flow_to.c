/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_edge_augment_flow_to.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 14:49:58 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_edge_augment_flow_to(void)
{
	t_flow_edge *edge;

	ft_printf("Testing edge_augment_flow_to: ");
	edge = edge_make(4, 2);
	assert(edge->from == 4);
	assert(edge->to == 2);
	assert(edge->flow == 0);

	assert(edge_augment_flow_to(edge, 2) == OK);
	assert(edge->from == 4);
	assert(edge->to == 2);
	assert(edge->flow == 1);

	assert(edge_augment_flow_to(edge, 4) == OK);
	assert(edge->from == 4);
	assert(edge->to == 2);
	assert(edge->flow == 0);

	assert(edge_augment_flow_to(edge, 2) == OK);
	assert(edge_augment_flow_to(edge, 2) == ERROR);
	assert(edge->from == 4);
	assert(edge->to == 2);
	assert(edge->flow == 1);

	assert(edge_augment_flow_to(edge, 4) == OK);
	assert(edge->from == 4);
	assert(edge->to == 2);
	assert(edge->flow == 0);
	assert(edge_augment_flow_to(edge, 4) == OK);
	assert(edge->from == 2);
	assert(edge->to == 4);
	assert(edge->flow == 1);

	assert(edge_augment_flow_to(edge, 4) == ERROR);
	assert(edge->from == 2);
	assert(edge->to == 4);
	assert(edge->flow == 1);


	assert(edge_augment_flow_to(edge, 2) == OK);
	assert(edge->from == 2);
	assert(edge->to == 4);
	assert(edge->flow == 0);
	assert(edge_augment_flow_to(edge, 2) == OK);
	assert(edge->from == 4);
	assert(edge->to == 2);
	assert(edge->flow == 1);

	assert(edge_augment_flow_to(edge, 1) == ERROR);
	assert(edge_augment_flow_to(edge, 0) == ERROR);
	assert(edge_augment_flow_to(edge, -1) == ERROR);
	edge_free(&edge);
	assert(edge == NULL);

	ft_printf("OK\n");
}
