/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:19:45 by cchen             #+#    #+#             */
/*   Updated: 2022/03/14 23:15:52 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*pad_results(t_specs specs, char *src)
{
	char	*padding;
	char	*res;

	if (specs.value == 0 && !(specs.flags & ZERO)
		&& specs.precision_on && !specs.precision
		&& specs.width
		&& !(specs.flags & HASH && specs.spec == 'o'))
		*src = '\0';
	padding = mod_flags(specs, ft_strlen(src));
	if (specs.spec == 'p' && !specs.value
		&& specs.precision_on && !specs.precision)
	{
		ft_strdel(&src);
		return (padding);
	}
	res = ft_strjoin(padding, src);
	ft_strdel(&src);
	ft_strdel(&padding);
	return (res);
}

char	*mod_char(t_specs *specs)
{
	char	*res;

	specs->value = va_arg(specs->ap, int);
	specs->sign = 1 - (((char) specs->value < 0) * 2);
	if (specs->is_signed)
		specs->value *= specs->sign;
	res = ft_uitoa((unsigned char) specs->value,
			get_int_base(specs->spec), specs->spec == 'X');
	return (pad_results(*specs, res));
}

char	*mod_short(t_specs *specs)
{
	char	*res;

	specs->value = va_arg(specs->ap, int);
	specs->sign = 1 - (((short) specs->value < 0) * 2);
	if (specs->is_signed)
		specs->value *= specs->sign;
	res = ft_ultoa((unsigned short) specs->value,
			get_int_base(specs->spec), specs->spec == 'X');
	return (pad_results(*specs, res));
}

char	*mod_int(t_specs *specs)
{
	char	*res;

	specs->value = va_arg(specs->ap, int);
	specs->sign = 1 - ((specs->value < 0) * 2);
	if (specs->is_signed)
		specs->value *= specs->sign;
	res = ft_uitoa(specs->value, get_int_base(specs->spec), specs->spec == 'X');
	return (pad_results(*specs, res));
}

char	*mod_long(t_specs *specs)
{
	char	*res;

	specs->value = va_arg(specs->ap, long);
	specs->sign = 1 - ((specs->value < 0) * 2);
	if (specs->is_signed)
		specs->value *= specs->sign;
	res = ft_ultoa(specs->value, get_int_base(specs->spec), specs->spec == 'X');
	return (pad_results(*specs, res));
}
