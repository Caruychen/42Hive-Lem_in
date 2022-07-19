/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:35:07 by cchen             #+#    #+#             */
/*   Updated: 2022/07/19 22:20:25 by cchen            ###   ########.fr       */
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

#include "hashmap.h"

static int	_guards(t_hashmap *dst, char *key)
{
	if (!dst || !key)
		return (HASH_ERR);
	if (!dst->capacity && hashmap_new_with_capacity(dst, HASH_NEW_CAPACITY)
		== HASH_ERR)
		return (HASH_ERR);
	if (!dst->entries)
		return (HASH_ERR);
	if (dst->len >= dst->capacity)
		return (ft_putendl_fd(MSG_ERR_HASHMAP_FULL, 2), HASH_ERR);
	return (HASH_OK);
}

static t_entry	*_new_entry(t_hashmap *dst, t_entry new_entry, size_t index)
{
	t_entry	*entry_ptr;

	entry_ptr = &(dst->entries[index]);
	*entry_ptr = new_entry;
	if (!entry_ptr->key)
		return (NULL);
	return (dst->len++, entry);
}

t_entry	*hashmap_insert(t_hashmap *dst, char *key, int value)
{
	size_t	index;
	size_t	hash_index;
	size_t	available_index;
	size_t	end;
	t_entry	*entry;

	if (_guards(dst, key) == HASH_ERR)
		return (NULL);
	index = hashmap_hasher(dst, key);
	end = dst->capacity + index;
	available_index = dst->capacity;
	while (index < end)
	{
		hash_index = index % dst->capacity;
		entry = &(dst->entries[hash_index]);
		if (entry->key && !ft_strcmp(entry->key, key))
			return (entry->value = value, entry);
		if (!entry->key && hash_index < available_index)
			available_index = hash_index;
		index++;
	}
	return (_new_entry(dst, hashmap_create_entry(key, value), available_index));
}
