/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:06:07 by cchen             #+#    #+#             */
/*   Updated: 2022/07/20 14:24:20 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Frees hashmap and clears memory
 */

#include "hashmap.h"

void	hashmap_free(t_hashmap *src)
{
	size_t	index;
	t_entry	*entry;

	if (!src || !src->capacity)
		return ;
	if (!src->entries)
	{
		src->capacity = 0;
		src->len = 0;
		return ;
	}
	index = 0;
	while (index < src->capacity)
	{
		entry = &(src->entries[index]);
		if (entry->key)
			hashmap_free_entry(entry);
		index++;
	}
	free(src->entries);
	src->entries = NULL;
	src->capacity = 0;
	src->len = 0;
}
