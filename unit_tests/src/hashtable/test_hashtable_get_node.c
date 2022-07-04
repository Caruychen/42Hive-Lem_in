/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashtable_get_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:51:37 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/04 16:47:20 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_hashtable_get_node(void)
{
	t_vec		network;
	t_hashtable	htable;
	t_flow_node	*node;

	ft_printf("Testing hashtable_get_node: ");

	if (!network_init(&network))
		return ;
	if (!network_add_node(&network, ft_strdup("qpwoeiru")))
		return ;
	if (!network_add_node(&network, ft_strdup("abababa")))
		return ;
	if (!network_add_node(&network, ft_strdup("fdsaasdf")))
		return ;
	hashtable_from(&htable, &network);
	node = hashtable_get_node(&htable, "fdsaasdf");
	assert(!ft_strcmp(node->alias, "fdsaasdf"));
	node = hashtable_get_node(&htable, "qpwoeiru");
	assert(!ft_strcmp(node->alias, "qpwoeiru"));
	node = hashtable_get_node(&htable, "abababa");
	assert(!ft_strcmp(node->alias, "abababa"));
	network_free(&network);

	ft_printf("OK\n");
}
