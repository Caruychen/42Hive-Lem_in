/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/07/01 16:04:07 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_get_room(void)
{
	t_parser	parser;
	t_vec		network;
	t_flow_node	*node;
	int			ret;

	ft_printf("Testing get_room: ");

	network_init(&network);
	parser = (t_parser){.line = "1 2 3", .stage = ROOMS};
	ret = get_room(&parser, &network);
	node = vec_get(&network, 0);
	assert(ret == OK);
	assert(!ft_strcmp(node->alias, "1"));
	network_free(&network);

	network_init(&network);
	parser = (t_parser){.line = "start 0 0", .stage = ROOMS};
	ret = get_room(&parser, &network);
	node = vec_get(&network, 0);
	assert(ret == OK);
	assert(!ft_strcmp(node->alias, "start"));
	network_free(&network);

	//TODO: Assert that x-y coodrinates are being parsed correctly

	network_init(&network);
	parser = (t_parser){.line = "L1 1 1", .stage = ROOMS};
	ret = get_room(&parser, &network);
	assert(ret == ERROR);
	network_free(&network);

	network_init(&network);
	parser = (t_parser){.line = "1 2 3 4", .stage = ROOMS};
	ret = get_room(&parser, &network);
	assert(ret == ERROR);
	network_free(&network);

	network_init(&network);
	parser = (t_parser){.line = "1 2 3 ", .stage = ROOMS};
	ret = get_room(&parser, &network);
	assert(ret == ERROR);
	network_free(&network);

	network_init(&network);
	parser = (t_parser){.line = " 1 2 3", .stage = ROOMS};
	ret = get_room(&parser, &network);
	assert(ret == ERROR);
	network_free(&network);

	ft_printf("OK\n");
}
