/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_create_entry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:46:41 by cchen             #+#    #+#             */
/*   Updated: 2022/07/20 14:29:35 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
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
