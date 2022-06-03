/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:48:28 by cchen             #+#    #+#             */
/*   Updated: 2022/03/14 16:26:21 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dispatch.h"
#include "modifiers.h"

void	parse_length(const char **format, t_specs *specs)
{
	int	index;

	index = 0;
	while (index < LEN_FLAG_INDEX_MAX)
	{
		if (!(**format == 'h' || **format == 'l' || **format == 'L'))
			break ;
		if (**format == 'L')
		{
			(*format)++;
			specs->length = 1;
			break ;
		}
		if (!specs->length)
			specs->length = **format >> 2;
		else
			specs->length = ((**format & 0x0f) >> 2 == specs->length)
				* ~specs->length;
		index++;
		(*format)++;
	}
}
