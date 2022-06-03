/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:38:35 by cchen             #+#    #+#             */
/*   Updated: 2022/01/05 15:38:38 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "ft_math.h"

int	vec_resize(t_vec *src, size_t target_size)
{
	t_vec	dst;
	size_t	target_len;

	if (!src)
		return (-1);
	target_len = target_size / src->elem_size;
	if (vec_new(&dst, target_len, src->elem_size) < 0)
		return (-1);
	vec_copy(&dst, src);
	dst.len = ft_imin(target_len, src->len);
	vec_free(src);
	*src = dst;
	return (target_size);
}
