/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:56:11 by cchen             #+#    #+#             */
/*   Updated: 2022/07/19 14:26:53 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Gets the given key's corresponding entry in the map for in-place manipulation
 * returns a pointer to the entry.
 *
 * Otherwise, returns NULL if the key is not found.
 */

#include "hashmap.h"

t_entry	*hashmap_entry(t_hashmap *src, char *key)
{
	unsigned long	index;
	unsigned long	hash_index;
	unsigned long	end;
	t_entry			*entry;

	if (!src || !key || !src->capacity || !src->len)
		return (NULL);
	index = hashmap_hasher(src, key);
	end = src->capacity + index;
	while (index < end)
	{
		hash_index = index - (src->capacity * (index >= src->capacity));
		entry = &(src->entries[hash_index]);
		if (entry && !ft_strcmp(entry->key, key))
			return (entry);
		index++;
	}
	return (NULL);
}
