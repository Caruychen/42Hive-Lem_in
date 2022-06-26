/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:37:17 by carlnysten        #+#    #+#             */
/*   Updated: 2022/06/26 14:26:06 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_alias(t_parser *parser)
{
	char	*alias;
	char	*ptr;

	ptr = parser->line;
	if (*ptr == 'L')
		return (error(MSG_ERROR_ALIAS_L));
	while (*ptr == ' ')
		ptr++;
	ptr = ft_strchr(ptr, ' ');
	if (!ptr || !*(ptr + 1))
		return (error(MSG_ERROR_INVALID_LINE));
	//node_make(&node, ft_strndup(parser->line, ptr - parser->line)); // indices!
	alias = ft_strsub(parser->line, 0, ptr - parser->line); // indices!
	ft_putendl("room");
	ft_putendl(alias);
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

int	get_room(t_parser *parser)
{
	int			x;
	int			y;
	//t_flow_node	node;

	if (is_valid_link(parser))
	{
		parser->stage = LINKS;
		return (get_link(parser));
	}
	get_alias(parser);
	get_coordinate(parser, &x);
	get_coordinate(parser, &y);
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putnbr(y);
	ft_putchar('\n');
	return (1);
}
