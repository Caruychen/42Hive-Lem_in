/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 08:58:46 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/23 11:11:20 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "vec.h"
# include "hashmap.h"
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
	char		*line;
	char		*ptr;
	t_stage		stage;
	t_mod		modification;
	char		*source;
	char		*sink;
	int			room_count;
	int			edge_count;
	int			n_ants;
	t_hashmap	hmap;
}	t_parser;

typedef int	(*t_parse_func)(t_parser *, t_flow_network *);

int	parse_input(t_flow_network *network, t_info *info);
int	get_ant_number(t_parser *parser, t_flow_network *network);
int	get_room(t_parser *parser, t_flow_network *network);
int	get_link(t_parser *parser, t_flow_network *network);

#endif
