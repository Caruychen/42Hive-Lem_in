/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/06/27 21:23:16 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_get_room(void)
{
	t_parser	parser;
	t_vec		network;

	ft_printf("Testing get_room: ");

	network_init(&network);
	parser = (t_parser){"1 2 3", NULL, ROOMS, NONE, 0, 0, 0, 0, 0, 0};
	get_room(&parser, &network);

	ft_printf("OK\n");
}
