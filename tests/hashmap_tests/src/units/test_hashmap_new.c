/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashmap_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:23:27 by cchen             #+#    #+#             */
/*   Updated: 2022/07/20 15:26:22 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap_test.h"

void	test_hashmap_new(void)
{
	t_hashmap	hashmap;

	ft_printf("Testing hashmap_new\n");
	ft_printf("Default capacity = 0: ");
	assert(hashmap_new(&hashmap) == 0);
	assert(hashmap.capacity == 0);
	assert(hashmap.len == 0);
	assert(hashmap.entries == NULL);
	ft_printf("OK\n");
	ft_putendl("");
}
