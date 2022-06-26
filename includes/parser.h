/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 08:58:46 by carlnysten        #+#    #+#             */
/*   Updated: 2022/06/26 21:56:57 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define MSG_ERROR_INVALID_FILE "File did not contain ant number, rooms or links."
# define MSG_ERROR_INVALID_LINE "File contained an invalid line."
# define MSG_ERROR_GNL "Could not get next line."
# define MSG_ERROR_ALIAS_L "Invalid first character L in room alias."

# include "lem_in.h"

typedef enum
{
	ANT_NUMBER,
	ROOMS,
	LINKS,
}	t_stage;

typedef enum
{
	NONE,
	START,
	END
}	t_mod;

typedef struct s_parser
{
	char	*line;
	char	*ptr;
	t_stage	stage;
	t_mod	modification;
	int		gnl_ret;
	int		room_count;
	int		edge_count;
	int		n_ants;
}	t_parser;

typedef int	(*t_parse_func)(t_parser *, t_vec *);

int	parse_input(t_vec *network);
int	get_ant_number(t_parser *parser, t_vec *network);
int	get_room(t_parser *parser, t_vec *network);
int	get_link(t_parser *parser, t_vec *network);
int	is_valid_link(t_parser *parser, t_vec *network);

# endif
