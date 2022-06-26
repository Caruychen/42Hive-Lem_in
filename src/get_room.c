/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:37:17 by carlnysten        #+#    #+#             */
/*   Updated: 2022/06/27 00:32:14 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_alias(t_parser *parser, t_vec *network, char **alias)
{
	char	*ptr;

	ptr = parser->line;
	if (*ptr == 'L')
		return (error(MSG_ERROR_ALIAS_L));
	while (*ptr == ' ')
		ptr++;
	ptr = ft_strchr(ptr, ' ');
	if (!ptr || !*(ptr + 1))
	{
		parser->stage = LINKS;
		return (get_link(parser, network));
	}
	*alias = ft_strsub(parser->line, 0, ptr - parser->line);
	parser->ptr = ptr;
	return (OK);
}

static int	get_coordinate(t_parser *parser, int *coord)
{
	char	*ptr;

	ptr = parser->ptr;
	*coord = ft_atoi(ptr + 1);
	while (*(++ptr) && *ptr != ' ')
		if (!ft_isdigit(*ptr))
			return (error(MSG_ERROR_INVALID_LINE));
	parser->ptr = ptr;
	return (OK);
}

int	get_room(t_parser *parser, t_vec *network)
{
	char	*alias;
	int		x;
	int		y;

	if (get_alias(parser, network, &alias) == ERROR)
		return (ERROR);
	if (get_coordinate(parser, &x) == ERROR)
		return (ERROR);
	if (get_coordinate(parser, &y) == ERROR)
		return (ERROR);
	if (network_add_node(network, alias) == ERROR)
		return (ERROR);
	return (OK);
}
