/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_find_slot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:19:11 by cchen             #+#    #+#             */
/*   Updated: 2022/07/22 16:47:55 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "hashmap.h"

size_t	hashmap_find_slot(t_hashmap *src, const char *key)
{
	size_t	index;
	t_entry	entry;

	index = hashmap_hasher(src, key);
	entry = src->entries[index];
	while (entry.key && ft_strcmp(entry.key, key))
	{
		index = (index + 1) % src->capacity;
		entry = src->entries[index];
	}
	return (index);
}
