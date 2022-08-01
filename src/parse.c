/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:28:30 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/01 13:39:51 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static const t_parse_func	g_parser_jumptable[3] = {
	parse_ant_number,
	parse_room,
	parse_link
};

static int	check_for_modification(t_parser *parser)
{
	if (ft_strcmp(parser->line, "##start") == 0)
		parser->modification = START;
	else if (ft_strcmp(parser->line, "##end") == 0)
		parser->modification = END;
	if (parser->stage != ROOMS && parser->modification != NONE)
		return (error(MSG_ERROR_MOD));
	return (OK);
}

int	parse_input(t_flow_network *network)
{
	t_parser	parser;

	parser = (t_parser){0};
	while (1)
	{
		if (get_next_line(0, &parser.line) == ERROR)
			return (error(MSG_ERROR_GNL));
		if (!parser.line)
			break ;
		if (parser.line[0] == '#')
		{
			if (check_for_modification(&parser) == ERROR)
				return (ft_strdel(&parser.line), ERROR);
		}
		else if (g_parser_jumptable[parser.stage](&parser, network) == ERROR)
			return (ft_strdel(&parser.line), ERROR);
		ft_putendl(parser.line);
		ft_strdel(&parser.line);
	}
	if (parser.stage != LINKS)
		return (error(MSG_ERROR_INV_FILE));
	ft_putchar('\n');
	return (OK);
}
