/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:28:38 by cchen             #+#    #+#             */
/*   Updated: 2022/07/19 14:32:58 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Returns a pointer to value corresponding to the key
 *
 * If the corresponding key is not found, returns NULL
 */

#include "hashmap.h"

int				*hashmap_get(t_hashmap *src, char *key)
{
	t_entry	*entry;

	entry = hashmap_entry(src, key);
	if (!entry)
		return (NULL);
	return (&(entry->value));
}
