/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_hasher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:48:33 by cchen             #+#    #+#             */
/*   Updated: 2022/07/19 12:53:47 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

unsigned long	hashmap_hasher(t_hashmap *dst, char *str)
{
	unsigned long	hash;

	hash = DJB2_SEED;
	while (*str)
	{
		hash = ((hash << 5) + hash) + *str;
		str++;
	}
	return (hash % dst->capacity);
}
