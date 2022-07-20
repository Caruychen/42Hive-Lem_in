/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashmap_new_with_capacity.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:49:34 by cchen             #+#    #+#             */
/*   Updated: 2022/07/20 15:21:53 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap_test.h"

void	test_hashmap_new_with_capacity(void)
{
	t_hashmap	hashmap;

	ft_printf("Testing Hashmap_new_with_capacity\n");
	ft_printf("Capacity = 0: ");
	assert(hashmap_new_with_capacity(&hashmap, 0) == 0);
	assert(hashmap.capacity == 0);
	assert(hashmap.len == 0);
	assert(hashmap.entries == NULL);
	ft_printf("OK\n");

	ft_printf("Capacity = 1: ");
	assert(hashmap_new_with_capacity(&hashmap, 1) == HASH_OK);
	assert(hashmap.capacity == 1);
	assert(hashmap.len == 0);
	assert(hashmap.entries != NULL);
	assert(hashmap.entries[0].key == NULL);
	assert(hashmap.entries[0].value == 0);
	ft_printf("OK\n");

	hashmap_free(&hashmap);
	assert(hashmap.capacity == 0);
	assert(hashmap.len == 0);
	assert(hashmap.entries == NULL);

	ft_printf("Capacity = 42: ");
	assert(hashmap_new_with_capacity(&hashmap, 42) == HASH_OK);
	assert(hashmap.capacity == 42);
	assert(hashmap.len == 0);
	assert(hashmap.entries != NULL);
	assert(hashmap.entries[0].key == NULL);
	assert(hashmap.entries[0].value == 0);
	assert(hashmap.entries[21].key == NULL);
	assert(hashmap.entries[21].value == 0);
	assert(hashmap.entries[41].key == NULL);
	assert(hashmap.entries[41].value == 0);
	ft_printf("OK\n");

	hashmap_free(&hashmap);
	assert(hashmap.capacity == 0);
	assert(hashmap.len == 0);
	assert(hashmap.entries == NULL);
	ft_putendl("");
}
