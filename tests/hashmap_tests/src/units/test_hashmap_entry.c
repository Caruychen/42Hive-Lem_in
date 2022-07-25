/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashmap_entry.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:15:20 by cchen             #+#    #+#             */
/*   Updated: 2022/07/22 12:42:35 by cchen            ###   ########.fr       */
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

static void	add_key(t_hashmap *hashmap, char *key, int value)
{
	size_t	hash;

	hash = hashmap_hasher(hashmap, key);
	ft_printf("Key = '%s', natural hash = '%ld', value = '%d'\n", key, hash, value);
	assert(hashmap_entry(hashmap, key) == NULL);
	assert(hashmap_insert(hashmap, key, value) != NULL);
}

static void	test_assert(t_hashmap *hashmap, char *key, int value)
{
	t_entry	*entry;

	entry = hashmap_entry(hashmap, key);
	assert(strcmp(entry->key, key) == 0);
	assert(entry->value == value);
}

void	test_hashmap_entry(void)
{
	t_hashmap	hashmap;
	size_t		capacity;

	ft_printf("Testing hashmap_entry\n");
	capacity = 6;
	ft_printf("Creating the following hashmap with init capacity = %ld:\n", capacity);
	assert(hashmap_new_with_capacity(&hashmap, capacity));
	assert(hashmap_entry(&hashmap, "g") == NULL);
	add_key(&hashmap, "a", 'a');
	add_key(&hashmap, "b", 'b');
	add_key(&hashmap, "c", 'c');
	add_key(&hashmap, "d", 'd');
	add_key(&hashmap, "e", 'e');
	add_key(&hashmap, "f", 'f');
	ft_printf("Result: ");
	test_assert(&hashmap, "a", 'a');
	test_assert(&hashmap, "b", 'b');
	test_assert(&hashmap, "c", 'c');
	test_assert(&hashmap, "d", 'd');
	test_assert(&hashmap, "e", 'e');
	test_assert(&hashmap, "f", 'f');
	assert(hashmap_entry(&hashmap, "g") == NULL);
	ft_printf("OK\n\n");
	clear(&hashmap);
}
