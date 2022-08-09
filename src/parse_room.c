/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:37:17 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/09 18:04:31 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static int	hashmap_from(t_hashmap *hmap, t_vec *adj_list)
{
	size_t	index;
	size_t	len;
	char	*alias;

	len = adj_list->len;
	index = 0;
	while (index < len)
	{
		alias = ((t_flow_node *) vec_get(adj_list, index))->alias;
		if (!hashmap_try_insert(hmap, alias, (int) index))
			return (ERROR);
		index++;
	}
	return (OK);
}

static int	start_links(t_parser *parser, t_flow_network *network)
{
	if (!ft_strchr(parser->line, '-'))
		return (error(MSG_ERROR_INV_LINE));
	if (hashmap_new_with_capacity(&(parser->hmap), network->adj_list.len * 1.33)
		== HASH_ERR)
		return (error(MSG_ERR_HASH_INIT));
	if (hashmap_from(&(parser->hmap), &(network->adj_list)) == ERROR)
		return (hashmap_free(&(parser->hmap)), ERROR);
	parser->stage = LINKS;
	return (parse_link(parser, network));
}

static int	is_valid_line(char **room)
{
	int		index;
	char	*str;

	index = 0;
	while (room[index])
	{
		str = room[index++];
		if ((index == 1 && (*str == 'L' || ft_iswhitespace(*str)))
			|| (index > 1 && !ft_isnumber(str))
			|| index > 3)
			return (FALSE);
	}
	return (index == 3);
}

int	parse_room(t_parser *parser, t_flow_network *network)
{
	char	**room;

	room = ft_strsplit(parser->line, ' ');
	if (room[ALIAS] && !room[1])
		return (ft_strdelarray(&room), start_links(parser, network));
	if (!is_valid_line(room))
		return (ft_strdelarray(&room), error(MSG_ERROR_INV_LINE));
	if (network_add_node(network,
			ft_strdup(room[ALIAS]),
			ft_atoi(room[X_COORD]),
			ft_atoi(room[Y_COORD])) == ERROR)
		return (ft_strdelarray(&room), ERROR);
	if (parser->modification == START)
		network->source = network->adj_list.len - 1;
	else if (parser->modification == END)
		network->sink = network->adj_list.len - 1;
	parser->modification = NONE;
	ft_strdelarray(&room);
	return (OK);
}
