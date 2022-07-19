/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_new_with_capacity.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:54:47 by cchen             #+#    #+#             */
/*   Updated: 2022/07/19 13:52:37 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Creates an empty t_hashmap with specified capacity.
 *
 * The hashmap will be able to hold at least `capacity` elements without
 * reallocating. If capacity is 0, the hash map will not allocate
 */

#include "ft_stdlib.h"
#include "hashmap.h"

int	hashmap_new_with_capacity(t_hashmap *dst, size_t capacity)
{
	if (!dst)
		return (-1);
	dst->capacity = capacity;
	dst->len = 0;
	if (capacity == 0)
		return (dst->entries = NULL, 0);
	dst->entries = (t_entry *) ft_memalloc(capacity * sizeof(t_entry *));
	if (!dst->entries)
		return (dst->capacity = 0, -1);
	return (1);
}
