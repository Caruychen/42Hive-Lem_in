/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:16:28 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/12 10:51:08 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	printer_init(t_printer *printer, t_pathset *pathset)
{
	size_t	i;
	t_vec	line;

	if (vec_new(&printer->lines, pathset->steps, sizeof (t_vec)) == ERROR)
		return (ERROR);
	if (vec_from(&printer->move, "L\0", 2, sizeof (char)) == ERROR)
		return (ERROR);
	i = 0;
	while (i < pathset->steps)
	{
		vec_new(&line, 8, sizeof (char));
		vec_push(&printer->lines, &line);
		i++;
	}
	printer->ant_number = 0;
	printer->start_line = 0;
	printer->dash_id = 0;
	return (OK);
}

int	has_ants_to_send(t_pathset *pathset)
{
	static t_path	*shortest_path;

	if (!shortest_path)
		shortest_path = vec_get(&pathset->paths, 0);
	return (shortest_path->ants > 0);
}

void	put_line(void *ptr)
{
	write(1, ((t_vec *)ptr)->memory, ((t_vec *)ptr)->len - 1);
	ft_putchar('\n');
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

void	printer_free(t_printer *printer)
{
	size_t	i;
	t_vec	*line;

	i = 0;
	while (i < printer->lines.len)
	{
		line = vec_get(&printer->lines, i);
		if (line && line->memory)
			vec_free(line);
		i++;
	}
	if (printer->lines.memory)
		vec_free(&printer->lines);
	if (printer->move.memory)
		vec_free(&printer->move);
}
