/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:28:30 by carlnysten        #+#    #+#             */
/*   Updated: 2022/06/26 13:25:59 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "parser.h"
#include "lem_in.h"

static const t_parse_func	g_parser_jumptable[3] = {
	get_ant_number,
	get_room,
	get_link
};

int	parse_input(void)
{
	t_parser	parser;

	parser = (t_parser){NULL, NULL, ANT_NUMBER, NONE, 0, 0, 0, 0};
	while (1)
	{
		parser.gnl_ret = get_next_line(0, &parser.line);
		if (parser.gnl_ret == -1)
			return (error(MSG_ERROR_GNL));
		if (!parser.line)
			break ;
		if (parser.line[0] == '#')
		{
			if (ft_strcmp(parser.line, "##start") == 0)
				parser.modification = START;
			else if (ft_strcmp(parser.line, "##end") == 0)
				parser.modification = END;
			ft_strdel(&parser.line);
			continue ;
		}
		g_parser_jumptable[parser.stage](&parser);
		ft_strdel(&parser.line);
	}
	if (parser.stage == LINKS)
		return (1);
	return (error(MSG_ERROR_INVALID_FILE));
}
