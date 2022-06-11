/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_edge_list_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:16:17 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 16:19:51 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_edge_list_push(void)
{

	t_vec edge_list;
	t_flow_edge *e1;
	t_flow_edge *e2;
	t_flow_edge *e3;

	ft_printf("Testing edge_list_push: ");
	edge_list_make(&edge_list);
	e1 = edge_make(1, 2);
	e2 = edge_make(3, 4);
	e3 = edge_make(4, 0);

	assert(edge_list_push(&edge_list, e1) == 1);
	assert(edge_list.len == 1);
	assert(edge_list_get(&edge_list, 0)->from == e1->from);
	assert(edge_list_get(&edge_list, 0)->to == e1->to);
	assert(edge_list_get(&edge_list, 0)->flow == e1->flow);
	assert(edge_list_get(&edge_list, 0) == e1);

	assert(edge_list_push(&edge_list, e2) == 2);
	assert(edge_list.len == 2);
	assert(edge_list_get(&edge_list, 1)->from == e2->from);
	assert(edge_list_get(&edge_list, 1)->to == e2->to);
	assert(edge_list_get(&edge_list, 1)->flow == e2->flow);
	assert(edge_list_get(&edge_list, 1) == e2);

	assert(edge_list_push(&edge_list, e3) == 3);
	assert(edge_list.len == 3);
	assert(edge_list_get(&edge_list, 2)->from == e3->from);
	assert(edge_list_get(&edge_list, 2)->to == e3->to);
	assert(edge_list_get(&edge_list, 2)->flow == e3->flow);
	assert(edge_list_get(&edge_list, 2) == e3);

	edge_list_free(&edge_list);
	assert(edge_list.len == 0);
	assert(edge_list.elem_size == 0);
	assert(edge_list.alloc_size == 0);
	assert(edge_list.memory == NULL);
	ft_printf("OK\n");
}
