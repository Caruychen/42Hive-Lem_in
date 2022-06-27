/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_ant_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/06/27 21:23:48 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_get_ant_number(void)
{
	t_parser	parser;
	t_vec		network;

	ft_printf("Testing get_ant_number: ");

	parser = (t_parser){"1", NULL, ANT_NUMBER, NONE, 0, 0, 0, 0, 0, 0};
	get_ant_number(&parser, &network);
	assert(parser.n_ants == 1);

	ft_printf("OK\n");
}
