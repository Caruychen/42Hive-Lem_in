/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:28:30 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/17 13:35:18 by cchen            ###   ########.fr       */
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
		return (ft_strdel(&parser->line), OK);
	if (vec_append_str(&parser->inputs, parser->line) == ERROR
		|| vec_append_str(&parser->inputs, "\n") == ERROR)
		return (ERROR);
	return (ft_strdel(&parser->line), OK);
}

static int	save_input(t_vec *dst, t_vec *src)
{
	if (vec_append_str(src, "\n") == ERROR
		|| vec_from(dst, src->memory, src->len, src->elem_size) == ERROR)
		return (ERROR);
	return (OK);
}

int	parse_input(t_flow_network *network, t_options *options, t_vec *inputs)
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
		if (append_buffer(&parser, options->flags == QUIET) == ERROR)
			return (parser_free(&parser), ERROR);
	}
	if (parser.stage != LINKS)
		return (parser_free(&parser), error(MSG_ERROR_INV_FILE));
	if (save_input(inputs, &parser.inputs) == ERROR)
		return (parser_free(&parser), error(MSG_ERROR_MALLOC));
	return (parser_free(&parser), OK);
}
