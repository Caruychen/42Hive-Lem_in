/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:37:17 by carlnysten        #+#    #+#             */
/*   Updated: 2022/06/26 22:02:33 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_alias(t_parser *parser, char **alias)
{
	char	*ptr;

	ptr = parser->line;
	if (*ptr == 'L')
		return (error(MSG_ERROR_ALIAS_L));
	while (*ptr == ' ')
		ptr++;
	ptr = ft_strchr(ptr, ' ');
	if (!ptr || !*(ptr + 1))
		return (error(MSG_ERROR_INVALID_LINE));
	*alias = ft_strsub(parser->line, 0, ptr - parser->line); // indices!
	parser->ptr = ptr;
	return (1);
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
	return (1);
}

int	get_room(t_parser *parser, t_vec *network)
{
	char	*alias;
	int			x;
	int			y;

	if (is_valid_link(parser, network))
	{
		parser->stage = LINKS;
		return (get_link(parser, network));
	}
	get_alias(parser, &alias);
	get_coordinate(parser, &x);
	get_coordinate(parser, &y);
	//ft_putendl("room");
	//ft_putendl(alias);
	//ft_putnbr(x);
	//ft_putchar('\n');
	//ft_putnbr(y);
	//ft_putchar('\n');
	network_add_node(network, alias);
	return (1);
}
