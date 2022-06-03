/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_append_strn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:39:21 by cchen             #+#    #+#             */
/*   Updated: 2022/02/17 13:41:07 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "ft_string.h"

int	vec_append_strn(t_vec *dst, const void *src, size_t n)
{
	size_t	new_size;
	int		ret;

	if (!dst || !src)
		return (-1);
	if (!dst->memory)
		vec_new(dst, 1, dst->elem_size);
	new_size = (dst->len + n) * dst->elem_size;
	if (dst->alloc_size < new_size)
	{
		if (dst->alloc_size * 2 < new_size)
			ret = vec_resize(dst, new_size);
		else
			ret = vec_resize(dst, dst->alloc_size * 2);
		if (ret < 0)
			return (-1);
	}
	ft_memcpy(&dst->memory[dst->elem_size * dst->len], src, n * dst->elem_size);
	dst->len += n;
	return (dst->len);
}
