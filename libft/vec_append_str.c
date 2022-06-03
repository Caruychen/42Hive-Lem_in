/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_append_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:42:50 by cchen             #+#    #+#             */
/*   Updated: 2022/02/17 17:29:00 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "ft_string.h"

int	vec_append_str(t_vec *dst, const void *src)
{
	size_t	n;

	n = ft_strlen(src);
	return (vec_append_strn(dst, src, n));
}
