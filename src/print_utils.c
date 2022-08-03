/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:16:28 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/02 14:33:39 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	has_ants_to_send(t_pathset *pathset)
{
	static t_path	*shortest_path;

	if (!shortest_path)
		shortest_path = vec_get(&pathset->paths, 0);
	return (shortest_path->ants > 0);
}

void	put_line(void *ptr)
{
	t_vec	*line;

	line = (t_vec *)ptr;
	((char *)line->memory)[line->len - 1] = '\n';
	vec_append_strn(line, "\0", 1);
	ft_putstr(((t_vec *)line)->memory);
}

void	update_move_prefix(t_printer *printer)
{
	char	*number_string;

	printer->move.len = 1;
	number_string = ft_itoa(printer->ant_number);
	if (!number_string)
		return ;
	vec_append_str(&printer->move, number_string);
	ft_strdel(&number_string);
	vec_append_strn(&printer->move, "-", 1);
	printer->dash_id = printer->move.len;
}
