/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_try_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:26:01 by cchen             #+#    #+#             */
/*   Updated: 2022/07/20 11:38:56 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Tries to insert a key-value pair into the map, and returns a pointer to
 * the entry.
 *
 * If the map alreaady had this key present, nothing is updated, and a NULL
 * is returned.
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

static t_entry	*_write_entry(t_entry *entry, char *key, int value)
{
	*entry = hashmap_create_entry(key, value);
	if (!entry->key)
		return (NULL);
	return (dst->len++, entry);
}

t_entry	*hashmap_try_insert(t_hashmap *dst, char *key, int value)
{
	size_t	index;
	t_entry	*entry;

	if (_guards(dst, key) == HASH_ERR)
		return (NULL);
	index = hashmap_find_slot(dst, key);
	entry = &(dst->entries[index]);
	if (entry->key)
		return (NULL);
	return (_write_entry(entry, key, value));
}
