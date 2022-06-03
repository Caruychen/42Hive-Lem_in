/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:25:11 by cchen             #+#    #+#             */
/*   Updated: 2022/02/22 10:34:40 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "ft_string.h"

int	vec_push(t_vec *dst, void *src)
{
	if (!dst || !src)
		return (-1);
	if (!dst->memory)
		vec_new(dst, 1, dst->elem_size);
	if (dst->len * dst->elem_size >= dst->alloc_size)
		if (vec_resize(dst, dst->alloc_size * 2) < 0)
			return (-1);
	ft_memcpy(&dst->memory[dst->elem_size * dst->len], src, dst->elem_size);
	dst->len++;
	return (dst->len);
}
