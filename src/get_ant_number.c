/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ant_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:37:51 by carlnysten        #+#    #+#             */
/*   Updated: 2022/06/27 16:09:40 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	get_ant_number(t_parser *parser, t_vec *network)
{
	char	*ptr;

	(void) network;
	ptr = parser->line;
	if (!ft_isdigit(*ptr))
		return (error(MSG_ERROR_INV_LINE));
	while (*(++ptr))
		if (!ft_isdigit(*ptr))
			return (error(MSG_ERROR_INV_LINE));
	parser->n_ants = ft_atoi(parser->line);
	parser->stage = ROOMS;
	return (1);
}

