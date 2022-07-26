/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:28:22 by cchen             #+#    #+#             */
/*   Updated: 2022/07/26 11:57:13 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

int	main(void)
{
	test_flow_edge();
	test_edge_list();
	test_parser();
	system("leaks test_lem-in");
	return (0);
}
