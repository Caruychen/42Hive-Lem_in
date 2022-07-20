/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashmap_create_entry.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:27:51 by cchen             #+#    #+#             */
/*   Updated: 2022/07/20 15:42:16 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap_test.h"
#include <limits.h>

static void	run_assertion(t_entry *entry, char *key, int value)
{
	ft_printf("key = '%s', value = %d: ", key, value);
	*entry = hashmap_create_entry(key, value);
	assert(strcmp(entry->key, key) == 0);
	assert(entry->value == value);
	ft_printf("OK\n");
}

static void	check_free(t_entry *entry)
{
	ft_printf("Freeing entry: ");
	hashmap_free_entry(entry);
	assert(entry->key == NULL);
	assert(entry->value == 0);
	ft_printf("OK\n");
}

static void	test_set(t_entry *entry, char *key, int value)
{
	run_assertion(entry, key, value);
	check_free(entry);
}

void	test_hashmap_create_entry(void)
{
	t_entry	entry;

	ft_printf("Testing hashmap_create_entry\n");
	test_set(&entry, "Hello World", 42);
	test_set(&entry, "A very big number", INT_MAX);
	test_set(&entry, "A very low number", INT_MIN);
	test_set(&entry, "", 0);
	test_set(&entry, "-1", -1);
	test_set(&entry, "1", 1);
}
