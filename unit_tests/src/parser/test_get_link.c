/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/06/26 22:13:48 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_get_link(void)
{
	t_parser	parser;
	t_vec		network;

	ft_printf("Testing get_link: ");

	network_init(&network);
	parser = (t_parser){"1-2", NULL, LINKS, NONE, 0, 0, 0, 0};
	get_link(&parser, &network);

	ft_printf("OK\n");
}