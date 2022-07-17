/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:37:17 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/17 11:42:21 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_alias(t_parser *parser, t_vec *network, char **alias)
{
	parser->ptr = parser->line;
	if (*parser->ptr == 'L' || *parser->ptr == ' ')
		return (error(MSG_ERROR_CHAR_ALIAS));
	parser->ptr = ft_strchr(parser->ptr, ' ');
	if (!parser->ptr)
	{
		if (ft_strchr(parser->line, '-'))
		{
			parser->stage = LINKS;
			return (get_link(parser, network));
		}
		return (error(MSG_ERROR_INV_LINE));
	}
	*alias = ft_strsub(parser->line, 0, parser->ptr - parser->line);
	return (OK);
}

static int	get_coordinate(t_parser *parser, int *coord)
{
	if (!parser->ptr || !*(parser->ptr + 1))
		return (error(MSG_ERROR_INV_LINE));
	*coord = ft_atoi(parser->ptr + 1);
	while (*(++parser->ptr) && *parser->ptr != ' ')
		if (!ft_isdigit(*parser->ptr))
			return (error(MSG_ERROR_INV_LINE));
	return (OK);
}

int	get_room(t_parser *parser, t_vec *network)
{
	char	*alias;
	long	id;
	int		x;
	int		y;

	if (get_alias(parser, network, &alias) == ERROR)
		return (ERROR);
	if (parser->stage == LINKS)
		return (OK);
	if (get_coordinate(parser, &x) == ERROR)
		return (ERROR);
	if (get_coordinate(parser, &y) == ERROR)
		return (ERROR);
	if (*parser->ptr != '\0')
		return (ERROR);
	if (network_add_node(network, alias) == ERROR)
		return (ERROR);
	find_flow_node(network, alias, &id);
	if (parser->modification == START)
		parser->source = id;
	if (parser->modification == END)
		parser->sink = id;
	parser->modification = NONE;
	parser->room_count++;
	return (OK);
}
