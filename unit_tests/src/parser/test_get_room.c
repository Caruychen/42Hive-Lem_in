/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/06/26 19:44:53 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_get_room(void)
{
	t_parser	parser;

	ft_printf("Testing get_room: ");

	parser = (t_parser){"1 2 3", NULL, ROOMS, NONE, 0, 0, 0, 0};
	get_room(&parser);

	ft_printf("OK\n");
}
