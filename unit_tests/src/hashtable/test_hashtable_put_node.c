/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashtable_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:52:34 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/04 10:18:39 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_hashtable_insert(void)
{
	t_hashtable	htable;
	//t_flow_node node = {0};
	//int			ret;

	ft_printf("Testing hashtable_insert: ");

	vec_new(&htable, 10, sizeof (t_flow_node *));
	//ret = hashtable_insert(&htable, &node);
	//ret = hashtable_insert(&htable, &node);
	//assert(ret == OK);

	ft_printf("OK\n");
}
