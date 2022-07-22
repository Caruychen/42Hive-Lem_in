/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:35:07 by cchen             #+#    #+#             */
/*   Updated: 2022/07/22 11:58:13 by cchen            ###   ########.fr       */
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

#include "ft_stdio.h"
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
	return (HASH_OK);
}

static t_entry	*get_slot(t_hashmap *dst, char *key)
{
	return (&(dst->entries[hashmap_find_slot(dst, key)]));
}

t_entry	*hashmap_insert(t_hashmap *dst, char *key, int value)
{
	t_entry	*entry;

	if (_guards(dst, key) == HASH_ERR)
		return (NULL);
	entry = get_slot(dst, key);
	if (entry->key)
		return (entry->value = value, entry);
	if (dst->len >= dst->capacity - 1 && hashmap_resize(dst) == HASH_ERR)
		return (NULL);
	entry = get_slot(dst, key);
	*entry = hashmap_create_entry(key, value);
	if (!entry->key)
		return (NULL);
	return (dst->len++, entry);
}
