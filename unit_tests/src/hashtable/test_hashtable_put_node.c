/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashtable_put_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:52:34 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/05 22:15:30 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_hashtable_put_node(void)
{
	t_hashtable	htable;
	t_flow_node node;
	int			ret;

	ft_printf("Testing hashtable_insert: ");

	vec_new(&htable, 10, sizeof (t_flow_node));
	ft_bzero(htable.memory, htable.alloc_size);

	node = (t_flow_node){.alias = "node1"};
	ret = hashtable_put_node(&htable, &node, 0);
	assert(ret == OK);
	assert(!ft_strcmp(((t_flow_node *)vec_get(&htable, 0))->alias, "node1"));
	
	vec_free(&htable);

	ft_printf("OK\n");
}
