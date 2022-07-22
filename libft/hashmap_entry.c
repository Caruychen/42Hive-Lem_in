/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:56:11 by cchen             #+#    #+#             */
/*   Updated: 2022/07/22 16:47:34 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Gets the given key's corresponding entry in the map for in-place manipulation
 * returns a pointer to the entry.
 *
 * Otherwise, returns NULL if the key is not found.
 */

#include "hashmap.h"

t_entry	*hashmap_entry(t_hashmap *src, const char *key)
{
	size_t	index;
	t_entry	*entry;

	if (!src || !key || !src->capacity || !src->len)
		return (NULL);
	index = hashmap_find_slot(src, key);
	entry = &(src->entries[index]);
	if (entry->key)
		return (entry);
	return (NULL);
}
