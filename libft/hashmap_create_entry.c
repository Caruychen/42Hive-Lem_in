/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_create_entry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:46:41 by cchen             #+#    #+#             */
/*   Updated: 2022/07/19 16:47:46 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

t_entry	hashmap_create_entry(char *key, int value)
{
	t_entry	entry;

	entry.key = ft_strdup(key);
	if (!entry.key)
		return (entry);
	entry.value = value;
	return (entry);
}
