/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:20:59 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/25 19:33:40 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	vec_iter(t_vec *vec, void (*f) (void *))
{
	size_t	i;

	if (!vec || !vec->memory || !f)
		return ;
	i = 0;
	while (i < vec->len)
		f(vec->memory + (i++ *vec->elem_size));
}
