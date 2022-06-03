/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:36:18 by cchen             #+#    #+#             */
/*   Updated: 2022/03/14 15:52:45 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	get_int_base(const char c)
{
	return (10 + 6 * (c == 'x' || c == 'X' || c == 'p') - 2 * (c == 'o'));
}

void	init_specs(t_specs *specs, va_list ap)
{
	va_copy(specs->ap, ap);
	reset_specs(specs);
}

void	reset_specs(t_specs *specs)
{
	specs->value = 0;
	specs->length = 0;
	specs->flags = 0;
	specs->precision = 0;
	specs->precision_on = 0;
	specs->width = 0;
	specs->pad_char = ' ';
	specs->sign = 0;
}

int	padding(t_vec *result, int length, char c, int trigger)
{
	if (trigger == 0)
		return (0);
	while (length-- > 0)
	{
		if (vec_push(result, &c) < 0)
			return (-1);
	}
	return (0);
}

int	read_option(const char **format, t_specs *specs)
{
	int	arg;

	if (**format == '*')
	{
		(*format)++;
		arg = va_arg(specs->ap, int);
		if (!ft_isdigit(**format))
			return (arg);
	}
	arg = ft_atoi(*format);
	if (**format == '-')
		(*format)++;
	while (ft_isdigit(**format))
		(*format)++;
	return (arg);
}
