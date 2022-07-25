/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:37:17 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/23 11:37:29 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static int	get_alias(t_parser *parser, char **alias)
{
	if (*parser->line == 'L' || *parser->line == ' ')
		return (error(MSG_ERROR_CHAR_ALIAS));
	*alias = ft_strsub(parser->line, 0, parser->ptr - parser->line);
	return (OK);
}

static int	get_coordinate(t_parser *parser, int *coord)
{
	if (!parser->ptr || !*(parser->ptr + 1))
		return (error(MSG_ERROR_INV_LINE));
	*coord = ft_atoi(parser->ptr + 1);
	while (*(++parser->ptr) && *parser->ptr != ' ')
		if (!ft_isdigit(*parser->ptr))
			return (error(MSG_ERROR_INV_LINE));
	return (OK);
}

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
	return (get_link(parser, network));
}

int	get_room(t_parser *parser, t_flow_network *network)
{
	char	*alias;
	int		x;
	int		y;

	parser->ptr = ft_strchr(parser->line, ' ');
	if (!parser->ptr)
		return (start_links(parser, network));
	if (get_alias(parser, &alias) == ERROR)
		return (ERROR);
	if (get_coordinate(parser, &x) == ERROR)
		return (ERROR);
	if (get_coordinate(parser, &y) == ERROR)
		return (ERROR);
	if (*parser->ptr != '\0')
		return (ERROR);
	if (network_add_node(network, alias, x, y) == ERROR)
		return (ERROR);
	if (parser->modification == START)
		parser->source = alias;
	else if (parser->modification == END)
		parser->sink = alias;
	parser->modification = NONE;
	parser->room_count++;
	return (OK);
}
