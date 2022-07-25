/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_try_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:26:01 by cchen             #+#    #+#             */
/*   Updated: 2022/07/22 11:57:32 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Tries to insert a key-value pair into the map, and returns a pointer to
 * the entry.
 *
 * If the map alreaady had this key present, nothing is updated. An error is 
 * reported and a NULL is returned.
 */

#include "ft_stdio.h"
#include "ft_string.h"
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

t_entry	*hashmap_try_insert(t_hashmap *dst, char *key, int value)
{
	t_entry	*entry;

	if (_guards(dst, key) == HASH_ERR)
		return (NULL);
	entry = get_slot(dst, key);
	if (entry->key)
		return (ft_putendl_fd(MSG_ERR_NO_KEY, 2), NULL);
	if (dst->len >= dst->capacity - 1 && hashmap_resize(dst) == HASH_ERR)
		return (NULL);
	entry = get_slot(dst, key);
	*entry = hashmap_create_entry(key, value);
	if (!entry->key)
		return (NULL);
	return (dst->len++, entry);
}
