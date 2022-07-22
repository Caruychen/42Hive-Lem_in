/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashmap_remove.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:12:28 by cchen             #+#    #+#             */
/*   Updated: 2022/07/22 14:06:31 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap_test.h"

static void	clear(t_hashmap *hashmap)
{
	hashmap_free(hashmap);
	assert(hashmap->capacity == 0);
	assert(hashmap->len == 0);
	assert(hashmap->entries == NULL);
}

static void	add_key(t_hashmap *hashmap, char *key)
{
	size_t	hash;

	hash = hashmap_hasher(hashmap, key);
	ft_printf("Key = '%s', natural hash = '%ld', value = '%d'\n", key, hash, hash);
	assert(hashmap_entry(hashmap, key) == NULL);
	assert(hashmap_insert(hashmap, key, hash) != NULL);
}

void	print_order(t_hashmap *hashmap)
{
	size_t	index;
	t_entry	entry;

	index = 0;
	while (index < hashmap->capacity)
	{
		entry = *(hashmap->entries + index);
		ft_printf("%ld => key: %s value: %d\n", index, entry.key, entry.value);
		index++;
	}
}

static void	validate_entry(t_entry *entry, char *key, int value)
{
	assert(entry != NULL);
	assert(strcmp(entry->key, key) == 0);
	assert(entry->value == value);
}

void	check_result_1(t_hashmap *hashmap)
{
	validate_entry(hashmap->entries, "g", 4);
	validate_entry(hashmap->entries + 1, "c", 0);
	assert(hashmap->entries[2].key == NULL);
	assert(hashmap->entries[2].value == 0);
	assert(hashmap->entries[3].key == NULL);
	assert(hashmap->entries[3].value == 0);
	validate_entry(hashmap->entries + 4, "a", 4);
	validate_entry(hashmap->entries + 5, "b", 5);
}

void	check_result_2(t_hashmap *hashmap)
{
	validate_entry(hashmap->entries, "c", 0);
	validate_entry(hashmap->entries + 1, "d", 1);
	assert(hashmap->entries[2].key == NULL);
	assert(hashmap->entries[2].value == 0);
	assert(hashmap->entries[3].key == NULL);
	assert(hashmap->entries[3].value == 0);
	validate_entry(hashmap->entries + 4, "g", 4);
	validate_entry(hashmap->entries + 5, "b", 5);
}

void	test_hashmap_remove(void)
{
	t_hashmap	hashmap;
	size_t		capacity = 6;

	ft_printf("Testing hashmap_remove\n");
	ft_printf("Creating hashmap with capacity = 6, len = 5\n");
	assert(hashmap_new_with_capacity(&hashmap, capacity));
	add_key(&hashmap, "a");
	add_key(&hashmap, "b");
	add_key(&hashmap, "g");
	add_key(&hashmap, "c");
	add_key(&hashmap, "d");
	print_order(&hashmap);

	ft_printf("Removing key 'd': ");
	assert(hashmap_remove(&hashmap, "d") == HASH_OK);
	check_result_1(&hashmap);
	ft_printf("OK\n\n");

	ft_printf("Adding entry 'd'\n");
	add_key(&hashmap, "d");
	ft_printf("Removing key 'a': ");
	assert(hashmap_remove(&hashmap, "a") == HASH_OK);
	check_result_2(&hashmap);
	ft_printf("OK\n");
	clear(&hashmap);
}
