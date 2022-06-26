/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:36 by cchen             #+#    #+#             */
/*   Updated: 2022/06/26 19:52:25 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	test_get_link(void)
{
	t_parser	parser;

	ft_printf("Testing get_link: ");

	parser = (t_parser){"1-2", NULL, LINKS, NONE, 0, 0, 0, 0};
	get_link(&parser);

	ft_printf("OK\n");
}
