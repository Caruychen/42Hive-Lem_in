/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 08:58:46 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/17 11:36:40 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lem_in.h"
# include "info.h"

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
	char	*line;
	char	*ptr;
	t_stage	stage;
	t_mod	modification;
	int		gnl_ret;
	long	source;
	long	sink;
	int		room_count;
	int		edge_count;
	int		n_ants;
}	t_parser;

typedef int	(*t_parse_func)(t_parser *, t_vec *);

int	parse_input(t_vec *network, t_info *info);
int	get_ant_number(t_parser *parser, t_vec *network);
int	get_room(t_parser *parser, t_vec *network);
int	get_link(t_parser *parser, t_vec *network);
int	is_valid_link(t_parser *parser, t_vec *network, long *from, long *to);
int	find_flow_node(t_vec *network, const char *alias, long *id);

#endif
