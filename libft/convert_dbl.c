/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:13:37 by cchen             #+#    #+#             */
/*   Updated: 2022/03/15 19:24:08 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	append_num(t_vec *vec, long double value)
{
	char	*s;
	int		len;

	s = ft_ultoa((unsigned long) value, 10, FALSE);
	if (!s)
		return (-1);
	len = ft_strlen(s);
	if (vec_append_strn(vec, s, len) == -1)
		len = -1;
	ft_strdel(&s);
	return (len);
}

static int	append_decimals(t_vec *vec, long double value,
		unsigned int precision, t_specs specs)
{
	size_t		len;
	char		*s;

	if ((specs.flags & HASH || !specs.precision_on || specs.precision)
		&& vec_push(vec, ".") == -1)
		return (-1);
	if (specs.precision_on && !specs.precision)
		return (vec->len);
	value = (value - (unsigned long) value) * ft_pow(10, precision);
	s = ft_ultoa((unsigned long) value, 10, FALSE);
	len = ft_strlen(s);
	if (precision > len)
	{
		padding(vec, precision - len, '0', TRUE);
		precision -= precision - len;
	}
	vec_append_strn(vec, s, len);
	ft_strdel(&s);
	return (vec->len);
}

static int	push_result(t_vec *result, t_vec *vec, t_specs specs)
{
	int		res;

	mod_doubles(result, vec, specs);
	res = vec_append(result, vec);
	if (res < 0)
	{
		vec_free(vec);
		return (-1);
	}
	if (padding(result, specs.width - vec->len, ' ',
			(specs.flags & DASH) && specs.width > vec->len))
		return (-1);
	vec_free(vec);
	return (res);
}

int	conv_dbl(t_vec *result, t_specs *specs)
{
	long double			value;
	unsigned int		precision;
	t_vec				vec;

	if (specs->length == L)
		value = va_arg(specs->ap, long double);
	else
		value = va_arg(specs->ap, double);
	specs->sign = 1 - 2 * ((1 / value) < 0);
	if (value < 0)
		value *= -1;
	if (vec_new(&vec, 1, sizeof(char)) == -1)
		return (-1);
	precision = 6 * !specs->precision_on + specs->precision;
	value = rounding(value, precision);
	append_num(&vec, value);
	append_decimals(&vec, value, precision, *specs);
	return (push_result(result, &vec, *specs));
}
