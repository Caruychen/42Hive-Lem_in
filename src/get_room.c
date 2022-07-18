/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:37:17 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/18 13:41:01 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static int	get_alias(t_parser *parser, char **alias)
{
	if (*parser->line == 'L' || *parser->line == ' ')
		return (error(MSG_ERROR_CHAR_ALIAS));
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

static int is_finished(t_parser *parser)
{
	parser->ptr = ft_strchr(parser->line, ' ');
	if (parser->ptr)
		return (FALSE);
	return (TRUE);
}

static int	start_links(t_parser *parser, t_vec *network)
{
	t_hashtable	htable;

	if (!ft_strchr(parser->line, '-'))
		return (error(MSG_ERROR_INV_LINE));
	htable = (t_hashtable){0};
	if (hashtable_from(&htable, network) == ERROR)
		return (ERROR);
	parser->stage = LINKS;
	return (get_link(parser, network));
}

int	get_room(t_parser *parser, t_vec *network)
{
	char	*alias;
	int		x;
	int		y;

	if (is_finished(parser))
		return (start_links(parser, network));
	if (get_alias(parser, &alias) == ERROR)
		return (ERROR);
	if (get_coordinate(parser, &x) == ERROR)
		return (ERROR);
	if (get_coordinate(parser, &y) == ERROR)
		return (ERROR);
	if (*parser->ptr != '\0')
		return (ERROR);
	if (network_add_node(network, alias, x, y) == ERROR)
		return (ERROR);
	if (parser->modification == START)
		parser->source = alias;
	else if (parser->modification == END)
		parser->sink = alias;
	parser->modification = NONE;
	parser->room_count++;
	return (OK);
}
