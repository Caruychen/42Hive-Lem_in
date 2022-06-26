/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:35:39 by carlnysten        #+#    #+#             */
/*   Updated: 2022/06/26 22:04:39 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_valid_link(t_parser *parser, t_vec *network)
{
	char	*ptr;
	char	*room1;
	char	*room2;

	(void) network;
	ptr = ft_strchr(parser->line, '-');
	if (!ptr)
		return (0);
	room1 = ft_strsub(parser->line, 0, ptr - parser->line);
	room2 = ft_strdup(ptr + 1);
	//ft_putendl(room1);
	//ft_putendl(room2);
	return (1);
}

int	get_link(t_parser *parser, t_vec *network)
{
	if (!is_valid_link(parser, network))
		return (0);
	return (1);
}

