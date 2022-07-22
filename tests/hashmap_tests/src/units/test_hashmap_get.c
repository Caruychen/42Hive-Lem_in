/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashmap_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:36:02 by cchen             #+#    #+#             */
/*   Updated: 2022/07/22 13:24:52 by cchen            ###   ########.fr       */
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

void	test_hashmap_get(void)
{
	t_hashmap	hashmap;
	size_t		capacity;

	ft_printf("Testing hashmap_get\n");
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
	assert(*hashmap_get(&hashmap, "a") == 'a');
	assert(*hashmap_get(&hashmap, "b") == 'b');
	assert(*hashmap_get(&hashmap, "c") == 'c');
	assert(*hashmap_get(&hashmap, "d") == 'd');
	assert(*hashmap_get(&hashmap, "e") == 'e');
	assert(*hashmap_get(&hashmap, "f") == 'f');
	assert(hashmap_get(&hashmap, "g") == NULL);
	ft_printf("OK\n\n");
	clear(&hashmap);

}
