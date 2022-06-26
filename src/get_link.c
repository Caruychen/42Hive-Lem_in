/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:35:39 by carlnysten        #+#    #+#             */
/*   Updated: 2022/06/27 01:33:31 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	find_flow_node(t_vec *network, const char *alias, long *id)
{
	size_t	i;
	t_flow_node	*node;

	i = 0;
	while (i < network->len)
	{
		node = vec_get(network, i);
		if (!ft_strcmp(alias, node->alias))
		{
			*id = (long) i;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int	is_valid_link(t_parser *parser, t_vec *network, long *from, long *to)
{
	char	*ptr;
	char	*alias;

	(void) network;
	ptr = ft_strchr(parser->line, '-');
	if (!ptr)
		return (FALSE);
	alias = ft_strsub(parser->line, 0, ptr - parser->line);
	if (!alias)
		return (error(MSG_ERROR_MALLOC_VLINK));
	find_flow_node(network, alias, from);
	ft_strdel(&alias);
	alias = ft_strdup(ptr + 1);
	if (!alias)
		return (error(MSG_ERROR_MALLOC_VLINK));
	find_flow_node(network, alias, to);
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
