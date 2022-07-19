/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_find_slot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:19:11 by cchen             #+#    #+#             */
/*   Updated: 2022/07/19 22:32:48 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

size_t	hashmap_find_slot(t_hashmap *src, char *key)
{
	size_t	index;
	t_entry	entry;

	index = hashmap_hasher(dst, key);
	entry = dst->entries[index];
	while (entry->key && !ft_strcmp(entry->key, key))
	{
		index = (index + 1) % src->capacity;
		entry = dst->entries[index];
	}
	return (index);
}
