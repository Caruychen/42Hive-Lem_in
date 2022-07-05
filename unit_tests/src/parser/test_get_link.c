/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/07/05 21:53:27 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_get_link(void)
{
	t_parser	parser;
	t_vec		network;
	t_flow_edge *edge1;
	t_flow_edge *edge2;
	t_flow_node	*node1;
	t_flow_node	*node2;
	int			ret;

	ft_printf("Testing get_link: ");

	network_init(&network);
	parser = (t_parser){.line = "1-2", .stage = LINKS};
	if (!network_add_node(&network, ft_strdup("1"), 4, 2))
		return ;
	if (!network_add_node(&network, ft_strdup("2"), 2, 1))
		return ;
	ret = get_link(&parser, &network);
	assert(ret == OK);

	node1 = vec_get(&network, 0);
	node2 = vec_get(&network, 1);
	edge1 = node_get(node1, 0);
	edge2 = node_get(node2, 0);
	assert(edge1 == edge2);
	assert(edge1->to == edge2->to);
	assert(edge1->from == edge2->from);
	network_free(&network);

	parser = (t_parser){.line = "", .stage = LINKS};
	ret = get_link(&parser, &network);
	assert(ret == ERROR);

	ft_printf("OK\n");
}
