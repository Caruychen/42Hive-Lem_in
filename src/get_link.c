/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:35:39 by carlnysten        #+#    #+#             */
/*   Updated: 2022/06/26 14:25:12 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_valid_link(t_parser *parser)
{
	char	*ptr;
	char	*room1;
	char	*room2;

	ptr = ft_strchr(parser->line, '-');
	if (!ptr)
		return (0);
	room1 = ft_strsub(parser->line, 0, ptr - parser->line);
	room2 = ft_strdup(ptr + 1);
	ft_putendl(room1);
	ft_putendl(room2);
	return (1);
}

int	get_link(t_parser *parser)
{
	if (!is_valid_link(parser))
		return (0);
	return (1);
}

