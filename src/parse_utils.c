/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:06:38 by cchen             #+#    #+#             */
/*   Updated: 2022/08/11 14:13:19 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parser_init(t_parser *parser)
{
	if (vec_new(&parser->inputs, RESIZE_FACTOR, sizeof(char)) == ERROR)
		return (ERROR);
	parser->line = NULL;
	parser->stage = 0;
	parser->modification = 0;
	parser->mods = 0;
	parser->hmap.capacity = 0;
	parser->hmap.len = 0;
	return (OK);
}

int	parse_readline(const int fd, char **line, int *res)
{
	return (*res = get_next_line(fd, line), *res);
}

void	parser_free(t_parser *parser)
{
	if (parser->line)
		ft_strdel(&parser->line);
	if (parser->inputs.memory)
		vec_free(&parser->inputs);
	hashmap_free(&parser->hmap);
}
