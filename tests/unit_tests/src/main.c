/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:28:22 by cchen             #+#    #+#             */
/*   Updated: 2022/08/19 15:20:30 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

int	main(void)
{
	test_flow_edge();
	test_edge_list();
	test_parser();
	test_bfs();
	system("leaks test_lem-in");
	return (0);
}
