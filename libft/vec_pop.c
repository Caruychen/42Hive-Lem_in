/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:43:56 by cchen             #+#    #+#             */
/*   Updated: 2022/08/02 16:31:42 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "ft_string.h"

int	vec_pop(void *dst, t_vec *src)
{
	if (!dst || !src)
		return (-1);
	if (!src->memory || src->len == 0)
		return (0);
	ft_memcpy(dst, vec_get(src, src->len - 1), src->elem_size);
	src->len--;
	return (1);
}
