/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_edge_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:46:04 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 14:25:44 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_edge_other(void)
{
	t_flow_edge *edge;
	
	ft_printf("Testing edge_other: ");
	edge = edge_make(1, 2);
	assert(edge_other(edge, 1) == 2);
	assert(edge_other(edge, 2) == 1);
	assert(edge_other(edge, 0) == ERROR);
	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(1, 1);
	assert(edge_other(edge, 1) == 1);
	assert(edge_other(edge, 1) == 1);
	assert(edge_other(edge, 0) == ERROR);
	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(0, 0);
	assert(edge_other(edge, 0) == 0);
	assert(edge_other(edge, 0) == 0);
	assert(edge_other(edge, 1) == ERROR);
	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(0, INT_MAX);
	assert(edge_other(edge, 0) == INT_MAX);
	assert(edge_other(edge, INT_MAX) == 0);
	assert(edge_other(edge, 1) == ERROR);
	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(0, LONG_MAX);
	assert(edge_other(edge, 0) == LONG_MAX);
	assert(edge_other(edge, LONG_MAX) == 0);
	assert(edge_other(edge, 1) == ERROR);
	edge_free(&edge);
	assert(edge == NULL);

	edge = edge_make(LONG_MAX, 0);
	assert(edge_other(edge, 0) == LONG_MAX);
	assert(edge_other(edge, LONG_MAX) == 0);
	assert(edge_other(edge, 1) == ERROR);
	edge_free(&edge);
	assert(edge == NULL);

	ft_printf("OK\n");
}
