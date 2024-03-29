/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/08/01 13:41:17 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static void	make_hash(t_hashmap *hmap, t_vec *network)
{
	size_t	index;
	char	*alias;

	assert(hashmap_new_with_capacity(hmap, network->len * 1.33) == HASH_OK);
	index = 0;
	while (index < network->len)
	{
		alias = ((t_flow_node *) vec_get(network, index))->alias;
		assert(hashmap_try_insert(hmap, alias, (int) index) != NULL);
		index++;
	}
}

void	test_parse_link(void)
{
	t_parser		parser;
	t_flow_network	network;
	t_flow_edge		*edge1;
	t_flow_edge		*edge2;
	t_flow_node		*node1;
	t_flow_node		*node2;
	int				ret;

	ft_printf("Testing parse_link: ");

	network_init(&network);
	parser = (t_parser){.line = "1-2", .stage = LINKS};
	assert(network_add_node(&network, ft_strdup("1"), 4, 2) != ERROR);
	assert(network_add_node(&network, ft_strdup("2"), 2, 1) != ERROR);
	make_hash(&(parser.hmap), &(network.adj_list));
	ret = parse_link(&parser, &network);
	assert(ret == OK);

	node1 = vec_get(&network.adj_list, 0);
	node2 = vec_get(&network.adj_list, 1);
	edge1 = node_get(node1, 0);
	edge2 = node_get(node2, 0);
	assert(edge1 == edge2);
	assert(edge1->to == edge2->to);
	assert(edge1->from == edge2->from);
	network_free(&network);
	hashmap_free(&parser.hmap);

	parser = (t_parser){.line = "", .stage = LINKS};
	ret = parse_link(&parser, &network);
	assert(ret == ERROR);

	ft_printf("OK\n");
}
