/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_edge_make.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:51:26 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 14:24:56 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_edge_make(void)
{
	t_flow_edge *edge;

	ft_printf("Testing basic edge creation and freeing: ");
	edge = edge_make(1, 2);
	assert(edge != NULL);
	assert(edge->from == 1);
	assert(edge->to == 2);
	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(1, 1);
	assert(edge->from == 1);
	assert(edge->to == 1);
	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(0, 0);
	assert(edge->from == 0);
	assert(edge->to == 0);
	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(0, INT_MAX);
	assert(edge->from == 0);
	assert(edge->to == INT_MAX);
	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(0, LONG_MAX);
	assert(edge->from == 0);
	assert(edge->to == LONG_MAX);
	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(LONG_MAX, LONG_MAX);
	assert(edge->from == LONG_MAX);
	assert(edge->to == LONG_MAX);
	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(LONG_MAX, 0);
	assert(edge->from == LONG_MAX);
	assert(edge->to == 0);
	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(-1, 0);
	assert(edge == NULL);

	edge = edge_make(0, -1);
	assert(edge == NULL);

	edge = edge_make(-1, -1);
	assert(edge == NULL);

	ft_printf("OK\n");
}

