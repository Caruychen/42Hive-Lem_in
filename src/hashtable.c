/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:38:18 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/03 19:40:11 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// djb2 hashing
size_t	hash_func(t_hashtable *htable, char *str)
{
	size_t	hash;

	hash = 5381;
	while (*str)
	{
		hash = ((hash << 5) + hash) + *str;
		str++;
	}
	return (hash % htable->alloc_size);
}

int	hashtable_from(t_hashtable *dst, t_vec *src)
{
	if (vec_new(dst, src->alloc_size * 1.33, src->elem_size) == ERROR)
		return (ERROR);
	
	return (OK);
}

int	hashtable_insert(t_hashtable *dst, char *alias)
{
	if (!dst)
		return (ERROR);
	return (vec_insert(dst, alias, hash_func(dst, alias)));
}

void	*hashtable_get(t_hashtable *src, char *alias)
{
	if (!alias || !src || !src->memory)
		return (NULL);
	return (vec_get(src, hash_func(src, alias)));
}
