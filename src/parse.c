/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:28:30 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/09 14:54:56 by cchen            ###   ########.fr       */
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
	vec_free(&parser->inputs);
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

static int	parser_init(t_parser *parser)
{
	if (vec_new(&parser->inputs, RESIZE_FACTOR, sizeof(char)) == ERROR)
		return (ERROR);
	parser->line = NULL;
	parser->stage = 0;
	parser->modification = 0;
	return (OK);
}

int	parse_input(t_flow_network *network, t_options *options)
{
	t_parser	parser;

	if (parser_init(&parser) == ERROR)
		return (ERROR);
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
		if ((!options->quiet || (parser.line[0] == '#' && parser.line[1] != '#'))
				&& (vec_append_str(&parser.inputs, parser.line) == ERROR
				|| vec_append_str(&parser.inputs, "\n") == ERROR))
			return (parser_free(&parser), ERROR);
		ft_strdel(&parser.line);
	}
	if (parser.stage != LINKS)
		return (parser_free(&parser), error(MSG_ERROR_INV_FILE));
	write(1, parser.inputs.memory, parser.inputs.len);
	return (parser_free(&parser), OK);
}
