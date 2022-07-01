/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/07/01 16:58:35 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_get_link(void)
{
	t_parser	parser;
	t_vec		network;
	int			ret;

	ft_printf("Testing get_link: ");

	network_init(&network);
	parser = (t_parser){.line = "1-2", .stage = LINKS};
	if (!network_add_node(&network, ft_strdup("1")))
		return ;
	if (!network_add_node(&network, ft_strdup("2")))
		return ;
	ret = get_link(&parser, &network);
	assert(ret == OK);
	network_free(&network);

	ft_printf("OK\n");
}
