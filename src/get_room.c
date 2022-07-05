/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:37:17 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/05 21:51:51 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	hash_network(t_vec *network)
{
	t_hashtable	htable;

	htable = (t_hashtable){0};
	if (hashtable_from(&htable, network) == ERROR)
		return (ERROR);
	network_free(network);
	*network = htable;
	return (OK);
}

static int	get_alias(t_parser *parser, t_vec *network, char **alias)
{
	char	*ptr;

	ptr = parser->line;
	if (*ptr == 'L' || *ptr == ' ')
		return (error(MSG_ERROR_CHAR_ALIAS));
	ptr = ft_strchr(ptr, ' ');
	if (!ptr)
	{
		if (ft_strchr(parser->line, '-'))
		{
			hash_network(network);
			parser->stage = LINKS;
			return (get_link(parser, network));
		}
		return (error(MSG_ERROR_INV_LINE));
	}
	*alias = ft_strsub(parser->line, 0, ptr - parser->line);
	parser->ptr = ptr;
	return (OK);
}

static int	get_coordinate(t_parser *parser, int *coord)
{
	char	*ptr;

	ptr = parser->ptr;
	if (!ptr || !*(ptr + 1))
		return (error(MSG_ERROR_INV_LINE));
	*coord = ft_atoi(ptr + 1);
	while (*(++ptr) && *ptr != ' ')
		if (!ft_isdigit(*ptr))
			return (error(MSG_ERROR_INV_LINE));
	parser->ptr = ptr;
	return (OK);
}

int	get_room(t_parser *parser, t_vec *network)
{
	char	*alias;
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
