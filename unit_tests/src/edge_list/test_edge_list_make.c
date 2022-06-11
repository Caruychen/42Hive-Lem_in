/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_edge_list_make.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:00:09 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 16:27:53 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_edge_list_make(void)
{
	t_vec	edge_list;
	int		res;

	ft_printf("Testing edge_list_make: ");
	res = edge_list_make(&edge_list);

	assert(res == (1 * sizeof(t_flow_edge *)));
	assert(edge_list.elem_size == sizeof(t_flow_edge *));
	assert(edge_list.len == 0);
	assert(edge_list.alloc_size == (1 * edge_list.elem_size));
	assert(edge_list.memory != NULL);

	edge_list_free(&edge_list);
	assert(edge_list.len == 0);
	assert(edge_list.elem_size == 0);
	assert(edge_list.alloc_size == 0);
	assert(edge_list.memory == NULL);

	ft_printf("OK\n");
}
