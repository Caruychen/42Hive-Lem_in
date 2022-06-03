/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:38:17 by cchen             #+#    #+#             */
/*   Updated: 2022/01/06 11:18:00 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include <stdlib.h>

int	vec_new(t_vec *dst, size_t init_alloc, size_t elem_size)
{
	if (!dst || init_alloc == 0 || elem_size == 0)
		return (-1);
	dst->alloc_size = init_alloc * elem_size;
	dst->elem_size = elem_size;
	dst->len = 0;
	dst->memory = malloc(dst->alloc_size);
	if (!dst->memory)
	{
		dst->alloc_size = 0;
		dst->elem_size = 0;
		return (-1);
	}
	return (dst->alloc_size);
}
