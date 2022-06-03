/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:52:57 by cchen             #+#    #+#             */
/*   Updated: 2022/03/15 13:49:56 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	parse_precision(const char **format, t_specs *specs)
{
	int	arg;

	if (**format != '.')
		return ;
	(*format)++;
	arg = read_option(format, specs);
	if (arg < 0)
		return ;
	specs->precision_on = 1;
	specs->precision = (unsigned int) arg;
}
