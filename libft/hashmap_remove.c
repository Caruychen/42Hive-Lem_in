/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:40:04 by cchen             #+#    #+#             */
/*   Updated: 2022/07/20 14:03:48 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Removes a key from the map, returning 1 if the key was
 * previously in the map.
 *
 * Otherwise, if the key is not found, an error is reported and returns a 0
 */

#include "ft_string.h"
#include "hashmap.h"

static int	_guards(t_hashmap *dst, char *key)
{
	if (!dst || !key)
		return (HASH_ERR);
	if (!dst->capacity || !dst->len)
		return (ft_putendl_fd(MSG_ERROR_HASHMAP_EMPTY, 2), HASH_ERR);
	if (!dst->entries)
		return (HASH_ERR);
	return (HASH_OK);
}

int	_search_forward(t_hashmap *dst, size_t index, size_t *next)
{
	size_t	hash;
	int		res;

	res = 1;
	while (res)
	{
		*next = (*next + 1) % dst->capacity;
		if (!dst->entries[*next].key)
			break;
		hash = hashmap_hasher(dst, dst->entries[next].key);
		if ((index <= *next && (hash <= index || *next < hash)) ||
			(index > *next && hash <= index && *next < hash))
			res = 0;
	}
	return (res);
}

int	hashmap_remove(t_hashmap *dst, char *key)
{
	size_t	index;
	size_t	next;
	t_entry	*entry;

	if (_guards(dst, key) == HASH_ERR)
		return (HASH_ERR);
	index = hashmap_find_slot(dst, key);
	entry = &(dst->entries[index]);
	if (!entry->key)
		return (ft_putendl_fd(MSG_ERR_NO_KEY, 2), HASH_ERR);
	next = index;
	while (1)
	{
		hashmap_free_entry(&(dst->entries[index]));
		if (_search_forward(dst, index, &next))
			break;
		dst->entries[index] = dst->entries[next];
		index = next;
	}
	return (HASH_OK);
}
