/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:34:49 by cchen             #+#    #+#             */
/*   Updated: 2022/01/06 11:17:37 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "ft_string.h"

int	vec_copy(t_vec *dst, t_vec *src)
{
	int	cpy_bytes;

	if (!dst || !src)
		return (-1);
	if (dst->alloc_size > src->len * src->elem_size)
		cpy_bytes = src->len * src->elem_size;
	else
		cpy_bytes = dst->alloc_size;
	ft_memcpy(dst->memory, src->memory, cpy_bytes);
	return (cpy_bytes);
}
