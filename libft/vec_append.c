/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:49:27 by cchen             #+#    #+#             */
/*   Updated: 2022/03/08 10:57:48 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "ft_string.h"

int	vec_append(t_vec *dst, t_vec *src)
{
	int		ret;
	size_t	new_size;

	if (!dst || !src || !src->memory)
		return (-1);
	if (!dst->memory)
		vec_new(dst, 1, dst->elem_size);
	new_size = dst->len * dst->elem_size + src->len * src->elem_size;
	if (dst->alloc_size < new_size)
	{
		if (dst->alloc_size * RESIZE_FACTOR < new_size)
			ret = vec_resize(dst, new_size);
		else
			ret = vec_resize(dst, dst->alloc_size * RESIZE_FACTOR);
		if (ret < 0)
			return (-1);
	}
	ft_memcpy(
		&dst->memory[dst->elem_size * dst->len],
		src->memory,
		src->len * src->elem_size);
	dst->len += src->len;
	return (dst->len);
}
