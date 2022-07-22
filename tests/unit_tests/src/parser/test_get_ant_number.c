/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_ant_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/07/01 17:07:13 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_get_ant_number(void)
{
	t_parser	parser;
	t_vec		network;
	int			ret;

	ft_printf("Testing get_ant_number: ");

	parser = (t_parser){.line = "1", .stage = ANT_NUMBER};
	ret = get_ant_number(&parser, &network);
	assert(parser.n_ants == 1);
	assert(ret == OK);

	parser = (t_parser){.line = "0", .stage = ANT_NUMBER};
	ret = get_ant_number(&parser, &network);
	assert(parser.n_ants == 0);
	assert(ret == OK);

	parser = (t_parser){.line = "42424242"};
	ret = get_ant_number(&parser, &network);
	assert(parser.n_ants == 42424242);
	assert(ret == OK);

	parser = (t_parser){.line = "-1"};
	ret = get_ant_number(&parser, &network);
	assert(ret == ERROR);

	parser = (t_parser){.line = ""};
	ret = get_ant_number(&parser, &network);
	assert(ret == ERROR);

	ft_printf("OK\n");
}
