/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:35:39 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/09 15:39:20 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	set_index(long *dst, t_hashmap *hmap, char *alias)
{
	int	*res;

	if (!alias)
		return (error(MSG_ERROR_MALLOC_VLINK));
	res = hashmap_get(hmap, alias);
	if (!res)
		return (error(MSG_ERR_HASH_GET));
	*dst = *res;
	ft_strdel(&alias);
	return (OK);
}

static int	is_valid_link(t_parser *parser, long *from, long *to)
{
	char	*ptr;

	ptr = ft_strchr(parser->line, '-');
	if (!ptr)
		return (FALSE);
	return (set_index(from, &(parser->hmap),
			ft_strsub(parser->line, 0, ptr - parser->line)) == OK
		&& set_index(to, &(parser->hmap), ft_strdup(ptr + 1)) == OK);
}

int	parse_link(t_parser *parser, t_flow_network *network)
{
	long		from;
	long		to;
	t_flow_edge	*edge;

	if (!is_valid_link(parser, &from, &to))
		return (error(MSG_ERROR_INV_LINK));
	edge = edge_make(from, to);
	if (!edge)
		return (ERROR);
	if (!network_add_edge(network, edge))
		return (ERROR);
	return (OK);
}
