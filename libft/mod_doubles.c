/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_doubles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:28:40 by cchen             #+#    #+#             */
/*   Updated: 2022/03/15 15:30:46 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	mod_doubles(t_vec *result, t_vec *vec, t_specs specs)
{
	char	*s;
	size_t	offset;

	s = mod_sign(specs);
	offset = ft_strlen(s);
	if (specs.flags & ZERO && vec_append_strn(result, s, offset) < 0)
		return (-1);
	if (padding(result, specs.width - vec->len - offset, specs.pad_char,
			!(specs.flags & DASH) && specs.width > vec->len))
		return (-1);
	if (!(specs.flags & ZERO) && vec_append_strn(result, s, offset) < 0)
		return (-1);
	ft_strdel(&s);
	return (0);
}
