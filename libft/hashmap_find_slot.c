/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_find_slot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:19:11 by cchen             #+#    #+#             */
/*   Updated: 2022/07/20 14:32:02 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "hashmap.h"

size_t	hashmap_find_slot(t_hashmap *src, char *key)
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
