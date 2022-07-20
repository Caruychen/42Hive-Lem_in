/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashmap_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:53:36 by cchen             #+#    #+#             */
/*   Updated: 2022/07/20 16:49:46 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap_test.h"

static void	validate_entry(t_entry *entry, char *key, int value)
{
	assert(entry != NULL);
	assert(strcmp(entry->key, key) == 0);
	assert(entry->value == value);
}

void	run_test_1(t_hashmap *hashmap, char *key, int value)
{
	t_entry		*entry;
	size_t		index = 0;

	entry = hashmap_insert(hashmap, key, value);
	assert(hashmap->entries != NULL);
	assert(hashmap->capacity == 2);
	assert(hashmap->len == 1);

	validate_entry(entry, key, value);

	if (hashmap->entries[1].key)
		index = 1;
	assert(strcmp(hashmap->entries[index].key, key) == 0);
	assert(hashmap->entries[index].value == value);
	assert(hashmap->entries[!index].key == NULL);
	assert(hashmap->entries[!index].value == 0);
	ft_printf("OK\n");
}

void	run_test_2(t_hashmap *hashmap, char *key, int value)
{
	t_entry	*entry;
	size_t	index = 0;

	entry = hashmap_insert(hashmap, key, value);
	assert(hashmap->entries != NULL);
	assert(hashmap->capacity == 2);
	assert(hashmap->len == 2);

	validate_entry(entry, key, value);
	if (strcmp(hashmap->entries[1].key, key) == 0)
		index = 1;
	assert(hashmap->entries[index].value == value);
	validate_entry(&(hashmap->entries[!index]), "Hello World", 21);
	ft_printf("OK\n");
}

void	test_hashmap_insert(void)
{
	t_hashmap	hashmap;

	ft_printf("Testing hashmap_insert\n");
	ft_printf("With capacity = 0, resulting capacity should be expanded: ");
	assert(hashmap_new_with_capacity(&hashmap, 0) == 0);
	run_test_1(&hashmap, "Hello World", 42);
	ft_printf("Editing key with new value: ");
	run_test_1(&hashmap, "Hello World", 21);
	ft_printf("Add another key: ");
	run_test_2(&hashmap, "Another entry", 24);

	hashmap_free(&hashmap);
	assert(hashmap.capacity == 0);
	assert(hashmap.len == 0);
	assert(hashmap.entries == NULL);

	ft_printf("With large capacity = 100000000: ");
	assert(hashmap_new_with_capacity(&hashmap, 100000000) == HASH_OK);
	t_entry *entry = hashmap_insert(&hashmap, "Hello World", 42);
	assert(hashmap.entries != NULL);
	assert(hashmap.capacity == 100000000);
	assert(hashmap.len == 1);
	validate_entry(entry, "Hello World", 42); 
	ft_printf("OK\n");
}
