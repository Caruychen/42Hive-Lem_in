/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ant_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:37:51 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/24 16:41:01 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parse_ant_number(t_parser *parser, t_flow_network *network)
{
	int	n_ants;

	if (!ft_isnumber(parser->line))
		return (error(MSG_ERROR_INV_LINE));
	n_ants = ft_atoi(parser->line);
	if (n_ants < 0)
		return (error(MSG_ERROR_NEGATIVE_ANTS));
	network->n_ants = (size_t) n_ants;
	if (network->n_ants == 0)
		return (error(MSG_ERROR_NO_ANTS));
	parser->stage = ROOMS;
	return (OK);
}
