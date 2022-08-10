/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:28:30 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/10 11:15:29 by cchen            ###   ########.fr       */
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
	if (parser->modification != NONE)
		return (error(MSG_ERROR_MOD));
	if (ft_strcmp(parser->line, "##start") == 0)
		parser->modification = START;
	if (ft_strcmp(parser->line, "##end") == 0)
		parser->modification = END;
	if (parser->mods & parser->modification)
		return (error(MSG_ERROR_MOD_DUP));
	parser->mods |= parser->modification;
	return (OK);
}

static int	append_buffer(t_parser *parser, uint8_t quiet)
{
	if (quiet && !(parser->line[0] == '#' && parser->line[1] != '#'))
		return (OK);
	return (vec_append_str(&parser->inputs, parser->line) != ERROR
		&& vec_append_str(&parser->inputs, "\n") != ERROR);
}

int	parse_input(t_flow_network *network, t_options *options)
{
	t_parser	parser;
	int			res;

	if (parser_init(&parser) == ERROR)
		return (ERROR);
	while (parse_readline(0, &parser.line, &res))
	{
		if (res == ERROR)
			return (parser_free(&parser), error(MSG_ERROR_GNL));
		if (parser.line[0] == '#')
		{
			if (check_for_modification(&parser) == ERROR)
				return (parser_free(&parser), ERROR);
		}
		else if (g_parser_jumptable[parser.stage](&parser, network) == ERROR)
			return (parser_free(&parser), ERROR);
		if (!append_buffer(&parser, options->quiet))
			return (parser_free(&parser), ERROR);
		ft_strdel(&parser.line);
	}
	if (parser.stage != LINKS)
		return (parser_free(&parser), error(MSG_ERROR_INV_FILE));
	vec_append_str(&parser.inputs, "\n");
	write(1, parser.inputs.memory, parser.inputs.len);
	return (parser_free(&parser), OK);
}
