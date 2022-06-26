/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_ant_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/06/26 19:41:47 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_get_ant_number(void)
{
	t_parser	parser;

	ft_printf("Testing get_ant_number: ");
	parser = (t_parser){"1", NULL, ANT_NUMBER, NONE, 0, 0, 0, 0};
	get_ant_number(&parser);
	assert(parser.n_ants == 1);
	/*
	edge = edge_make(4, 2);
	assert(edge->from == 4);
	assert(edge->to == 2);
	assert(edge->flow == 0);
	*/

	ft_printf("OK\n");
}
