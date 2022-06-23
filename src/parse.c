/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:28:30 by carlnysten        #+#    #+#             */
/*   Updated: 2022/06/23 09:01:34 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "filler.h"

static int	get_ant_number(t_parser *parser)
{
	return (1);
}

static int	get_rooms(t_parser *parser)
{
	while (1)
	{
		parser->gnl_ret = get_next_line(0, parser->line);
		if (parser->gnl_ret < 1)
			return (-1);
		if (is_comment(parser->line))
		{
			ft_strdel(&parser->line);
			continue ;
		}
		if (is_valid_link(parser->line))
			break ;
		if (!is_valid_room(parser))
			return (-1);
		node_make(); // Parsing like this might be slow (iterates line several times)
		// Flow node struct needs members for coordinates
	}
	return (1);
}

static int	get_links(t_parser *parser)
{
	return (1);
}

int	parse(void)
{
	t_parser	parser;

	if (!get_ant_number(&parser))
		return (-1);
	if (!get_rooms(&parser))
		return (-1);
	if (!get_links(&parser))
		return (-1);
	return (1);
}
