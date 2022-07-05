/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashtable_get_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:51:37 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/05 21:54:55 by carlnysten       ###   ########.fr       */
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
	if (!network_add_node(&network, ft_strdup("qpwoeiru"), 0, 0))
		return ;
	if (!network_add_node(&network, ft_strdup("abababa"), 0, 1))
		return ;
	if (!network_add_node(&network, ft_strdup("fdsaasdf"), 0, 2))
		return ;
	hashtable_from(&htable, &network);
	node = hashtable_get_node(&htable, "fdsaasdf");
	assert(node->alias != NULL);
	assert(!ft_strcmp(node->alias, "fdsaasdf"));
	node = hashtable_get_node(&htable, "qpwoeiru");
	assert(node->alias != NULL);
	assert(!ft_strcmp(node->alias, "qpwoeiru"));
	node = hashtable_get_node(&htable, "abababa");
	assert(node->alias != NULL);
	assert(!ft_strcmp(node->alias, "abababa"));
	network_free(&network);

	ft_printf("OK\n");
}
