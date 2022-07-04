/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashtable_from.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:50:10 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/04 14:49:34 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_hashtable_from(void)
{
	t_vec		network;
	t_hashtable	htable = {0};
	t_flow_node	*node;
	int			ret;

	ft_printf("Testing hashtable_from: ");

	if (!network_init(&network))
		return ;
	if (!network_add_node(&network, ft_strdup("abc")))
		return ;
	ret = hashtable_from(&htable, &network);
	assert(ret == OK);
	assert(htable.elem_size == sizeof (t_flow_node));
	assert(htable.len == 1);

	(void) node;
	network_free(&network);
	ft_printf("OK\n");
}
