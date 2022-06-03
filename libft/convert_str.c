/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:13:57 by cchen             #+#    #+#             */
/*   Updated: 2022/03/10 15:47:34 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	append_char(t_vec *result, t_specs *specs, char c)
{
	int	res;

	if (padding(result, specs->width - 1, specs->pad_char,
			!(specs->flags & DASH)))
		return (-1);
	res = vec_push(result, &c);
	if (res < 0)
		return (res);
	if (padding(result, specs->width - 1, specs->pad_char,
			specs->flags & DASH))
		return (-1);
	return (res);
}

int	conv_char(t_vec *result, t_specs *specs)
{
	char	c;

	c = va_arg(specs->ap, int);
	return (append_char(result, specs, c));
}

static int	push_str(t_vec *result, t_specs specs, char *str)
{
	size_t	length;
	int		res;

	length = ft_strlen(str);
	if (specs.precision_on && length > specs.precision)
		length = specs.precision;
	if (padding(result, specs.width - length, specs.pad_char,
			!(specs.flags & DASH)) < 0)
		return (-1);
	res = vec_append_strn(result, str, length);
	if (res < 0)
		return (res);
	if (padding(result, specs.width - length, specs.pad_char,
			specs.flags & DASH) < 0)
		return (-1);
	return (res);
}

int	conv_string(t_vec *result, t_specs *specs)
{
	char	*str;

	str = va_arg(specs->ap, char *);
	if (!str)
		str = "(null)";
	return (push_str(result, *specs, str));
}
