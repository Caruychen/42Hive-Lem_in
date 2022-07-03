/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:28:30 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/03 17:39:38 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static const t_parse_func	g_parser_jumptable[3] = {
	get_ant_number,
	get_room,
	get_link
};

static void	check_for_modification(t_parser *parser)
{
	if (ft_strcmp(parser->line, "##start") == 0)
		parser->modification = START;
	else if (ft_strcmp(parser->line, "##end") == 0)
		parser->modification = END;
}

int	parse_input(t_vec *network, t_info *info)
{
	t_parser	parser;

	parser = (t_parser){0};
	while (1)
	{
		parser.gnl_ret = get_next_line(0, &parser.line);
		if (parser.gnl_ret == -1)
			return (error(MSG_ERROR_GNL));
		if (!parser.line)
			break ;
		if (parser.line[0] == '#')
			check_for_modification(&parser);
		else if (g_parser_jumptable[parser.stage](&parser, network) == ERROR)
			return (ft_strdel(&parser.line), ERROR);
		ft_putendl(parser.line);
		ft_strdel(&parser.line);
	}
	if (parser.stage != LINKS)
		return (error(MSG_ERROR_INV_FILE));
	info->source = parser.source;
	info->sink = parser.sink;
	info->n_ants = parser.n_ants;
	ft_putchar('\n');
	return (OK);
}
