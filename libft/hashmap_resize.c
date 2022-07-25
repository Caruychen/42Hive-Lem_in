/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:54:41 by cchen             #+#    #+#             */
/*   Updated: 2022/07/22 14:09:55 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Resizes the hashmap by allocating a larger array, and uses the insert
 * operation to add all elements of the old array into the new larger array.
 *
 * The array size is increased exponentially by doubling the array size
 */

#include "hashmap.h"

static int	rehash(t_hashmap *dst, t_hashmap *src)
{
	size_t	index;
	size_t	capacity;
	t_entry	*entry;

	capacity = src->capacity;
	index = 0;
	while (index < capacity)
	{
		entry = &(src->entries[index]);
		if (entry->key && !hashmap_try_insert(dst, entry->key, entry->value))
			return (hashmap_free(dst), HASH_ERR);
		index++;
	}
	return (HASH_OK);
}

int	hashmap_resize(t_hashmap *src)
{
	t_hashmap	dst;
	size_t		target_cap;

	if (!src || !src->capacity || !src->entries)
		return (HASH_ERR);
	target_cap = src->capacity * HASH_NEW_CAPACITY;
	if (hashmap_new_with_capacity(&dst, target_cap) == HASH_ERR)
		return (HASH_ERR);
	if (rehash(&dst, src) == HASH_ERR)
		return (HASH_ERR);
	hashmap_free(src);
	return (*src = dst, HASH_OK);
}
