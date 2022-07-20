/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_free_entry.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:55:44 by cchen             #+#    #+#             */
/*   Updated: 2022/07/20 12:56:00 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

static int	free_entry(t_entry *entry)
{
	if (!entry || !entry->key)
		return (HASH_ERR);
	free(entry->key);
	entry->key = NULL;
	entry->value = 0;
	return (HASH_OK);
}
