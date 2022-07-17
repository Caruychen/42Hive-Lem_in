/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:35:39 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/17 17:54:38 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_valid_link(t_parser *parser, t_vec *network, long *from, long *to)
{
	char	*ptr;
	char	*alias;

	ptr = ft_strchr(parser->line, '-');
	if (!ptr)
		return (FALSE);
	alias = ft_strsub(parser->line, 0, ptr - parser->line);
	if (!alias)
		return (error(MSG_ERROR_MALLOC_VLINK));
	*from = hashtable_get_node_index(network, alias);
	ft_strdel(&alias);
	alias = ft_strdup(ptr + 1);
	if (!alias)
		return (error(MSG_ERROR_MALLOC_VLINK));
	*to = hashtable_get_node_index(network, alias);
	ft_strdel(&alias);
	return (TRUE);
}

int	get_link(t_parser *parser, t_vec *network)
{
	long		from;
	long		to;
	t_flow_edge	*edge;

	if (!is_valid_link(parser, network, &from, &to))
		return (ERROR);
	edge = edge_make(from, to);
	if (!edge)
		return (ERROR);
	if (!network_add_edge(network, edge))
		return (ERROR);
	return (OK);
}
