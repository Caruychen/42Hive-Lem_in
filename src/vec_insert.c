/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:17:49 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/03 16:25:06 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	vec_insert(t_vec *dst, void *src, size_t index)
{
	if (!dst || !src)
		return (ERROR);
	if (!dst->memory)
		vec_new(dst, 1, dst->elem_size);
	if (index >= dst->len)
		dst->len = index;
	if (dst->len * dst->elem_size >= dst->alloc_size)
		if (vec_resize(dst, dst->alloc_size * 2) < 0)
			return (ERROR);
	ft_memcpy(&dst->memory[dst->elem_size * index], src, dst->elem_size);
	dst->len++;
	return (dst->len);
}
