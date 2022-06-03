/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:16:11 by cchen             #+#    #+#             */
/*   Updated: 2022/03/15 13:58:57 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static inline int	is_null_precision(t_specs specs)
{
	return (specs.precision_on && !(specs.spec == 'o' && specs.flags & HASH)
		&& specs.precision == 0 && specs.value == 0 && !specs.width
		&& specs.spec != 'p');
}

static int	push_result(t_vec *result, t_specs specs, char *s)
{
	int		res;
	size_t	len;

	len = !is_null_precision(specs) * ft_strlen(s);
	res = vec_append_strn(result, s, len);
	if (res < 0)
		return (res);
	if (padding(result, specs.width - len, specs.pad_char, specs.flags & DASH))
		return (-1);
	return (res);
}

int	conv_num(t_vec *result, t_specs *specs)
{
	int		res;
	char	*s;
	char	spec;

	spec = specs->spec;
	if (specs->precision_on)
	{
		specs->flags &= ~(ZERO);
		specs->pad_char = ' ';
	}
	s = g_modifier[specs->length](specs);
	if (!s)
		return (-1);
	res = push_result(result, *specs, s);
	ft_strdel(&s);
	return (res);
}
