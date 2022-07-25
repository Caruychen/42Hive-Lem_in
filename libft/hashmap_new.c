/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:51:28 by cchen             #+#    #+#             */
/*   Updated: 2022/07/19 13:55:29 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Creates an empty Hashmap
 * The hash map is initially created with a capacity of 0,
 * so it will not allocate until it is first inserted into.
 */

#include "hashmap.h"

int	hashmap_new(t_hashmap *dst)
{
	return (hashmap_new_with_capacity(dst, 0));
}
