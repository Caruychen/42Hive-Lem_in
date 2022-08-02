/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:28:30 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/02 21:00:05 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static const t_parse_func	g_parser_jumptable[3] = {
	parse_ant_number,
	parse_room,
	parse_link
};

static void	parser_free(t_parser *parser)
{
	if (parser->line)
		ft_strdel(&parser->line);
	hashmap_free(&parser->hmap);
}

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

int	parse_input(t_flow_network *network, t_options *options)
{
	t_parser	parser;

	parser = (t_parser){0};
	while (1)
	{
		if (get_next_line(0, &parser.line) == ERROR)
			return (parser_free(&parser), error(MSG_ERROR_GNL));
		if (!parser.line)
			break ;
		if (parser.line[0] == '#')
		{
			if (check_for_modification(&parser) == ERROR)
				return (parser_free(&parser), ERROR);
		}
		else if (g_parser_jumptable[parser.stage](&parser, network) == ERROR)
			return (parser_free(&parser), ERROR);
		if (!options->quiet)
			ft_putendl(parser.line);
		ft_strdel(&parser.line);
	}
	if (parser.stage != LINKS)
		return (parser_free(&parser), error(MSG_ERROR_INV_FILE));
	if (!options->quiet)
		ft_putchar('\n');
	return (parser_free(&parser), OK);
}
