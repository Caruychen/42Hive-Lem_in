/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flow_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:08:46 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 14:41:11 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

int	test_flow_edge(void)
{
	test_edge_make();
	test_edge_other();
	test_edge_has_residual_capacity_to();
	test_edge_augment_flow_to();
	return (0);
}
