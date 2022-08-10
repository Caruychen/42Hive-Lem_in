/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 08:58:46 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/10 16:09:40 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "vec.h"
# include "hashmap.h"
# include "options.h"

# define ALIAS 0
# define X_COORD 1
# define Y_COORD 2
# define ALL_MODS 3

typedef enum e_stage
{
	ANT_NUMBER,
	ROOMS,
	LINKS,
}	t_stage;

typedef enum e_mod
{
	NONE,
	START,
	END
}	t_mod;

typedef struct s_parser
{
	t_vec		inputs;
	char		*line;
	char		*ptr;
	t_stage		stage;
	t_mod		modification;
	uint8_t		mods: 2;
	t_hashmap	hmap;
}	t_parser;

typedef int	(*t_parse_func)(t_parser *, t_flow_network *);

int		parser_init(t_parser *parser);
int		parse_readline(const int fd, char **line, int *res);
void	parser_free(t_parser *parser);

int		parse_input(t_flow_network *network, t_options *options, t_vec *inputs);
int		parse_ant_number(t_parser *parser, t_flow_network *network);
int		parse_room(t_parser *parser, t_flow_network *network);
int		parse_link(t_parser *parser, t_flow_network *network);

#endif
