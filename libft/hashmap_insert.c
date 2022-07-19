/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:35:07 by cchen             #+#    #+#             */
/*   Updated: 2022/07/19 17:10:12 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Inserts a key-value pair into the hashmap
 *
 * If the map did not have this key present, a new entry is made and a pointer
 * to the entry is returned.
 *
 * If the map did have this key present the value is updated. The key is not
 * updated. It will return a pointer to the entry that was updated.
 */

#include "hashmap.c"

static int	_guards(t_hashmap *dst, char *key)
{
	if (!dst || !key)
		return (HASH_ERR);
	if (!dst->capacity && hashmap_new_with_capacity(dst, HASH_NEW_CAPACITY) == HASH_ERR)
		return (HASH_ERR);
	if (!dst->entries)
		return (HASH_ERR);
	if (dst->len >= dst->capacity)
		return (ft_putendl_fd(MSG_ERR_HASHMAP_FULL, 2), HASH_ERR);
	return (HASH_OK);
}

static inline size_t _hash_index(size_t index, size_t capacity)
{
	return (index - (capacity * (index >= capacity)));
}

t_entry	*hashmap_insert(t_hashmap *dst, char *key, int value)
{
	size_t	index;
	size_t	hash_index;
	size_t	available_index;
	size_t	end;
	t_entry			*entry;

	if (_guards(dst, key) == HASH_ERR)
		return (NULL);
	index = hashmap_hasher(dst, key);
	end = dst->capacity + index;
	available_index = dst->capacity;
	while (index < end)
	{
		hash_index = _hash_index(index, dst->capacity);
		entry = &(dst->entries[hash_index]);
		if (entry->key && !ft_strcmp(entry->key, key))
			return (entry->value = value, entry);
		if (!entry->key && hash_index < available_index)
			available_index = hash_index;
		index++;
	}
	entry = &(dst->entries[available_index]);
	*entry = hashmap_create_entry(key, value);
	if (!entry->key)
		return (NULL);
	dst->len++;
	return (entry);
}
