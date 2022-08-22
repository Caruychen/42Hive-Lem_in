/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_ant_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/08/19 15:22:54 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "unit_test.h"

void	test_parse_ant_number(void)
{
	t_parser	parser;
	t_flow_network	network;
	int			ret;

	ft_printf("Testing parse_ant_number: ");

	parser = (t_parser){.line = "1", .stage = ANT_NUMBER};
	ret = parse_ant_number(&parser, &network);
	assert(network.n_ants == 1);
	assert(ret == OK);

	parser = (t_parser){.line = "0", .stage = ANT_NUMBER};
	ret = parse_ant_number(&parser, &network);
	assert(network.n_ants == 0);
	assert(ret == ERROR);

	parser = (t_parser){.line = "42424242"};
	ret = parse_ant_number(&parser, &network);
	assert(network.n_ants == 42424242);
	assert(ret == OK);

	parser = (t_parser){.line = "-1"};
	ret = parse_ant_number(&parser, &network);
	assert(ret == ERROR);

	parser = (t_parser){.line = ""};
	ret = parse_ant_number(&parser, &network);
	assert(ret == ERROR);

	ft_printf("OK\n");
}
