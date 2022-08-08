/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:47:54 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/03 11:42:33 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	printer_init(t_printer *printer, t_pathset *pathset)
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

static void	printer_free(t_printer *printer)
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

static void	send_ant(t_printer *printer)
{
	t_flow_node	*node;
	t_vec		*line;
	size_t		i;

	update_move_prefix(printer);
	i = 0;
	while (i < printer->path->nodes.len)
	{
		printer->move.len = printer->dash_id;
		node = vec_get(&printer->path->nodes, printer->path->nodes.len - i - 1);
		vec_append_str(&printer->move, node->alias);
		line = vec_get(&printer->lines, printer->start_line + i);
		vec_append_strn(line, printer->move.memory, printer->move.len);
		vec_append_strn(line, " ", 1);
		i++;
	}
}

static void	send_ant_wave(t_printer *printer, t_pathset *pathset)
{
	size_t	i;

	i = 0;
	while (i < pathset->paths.len)
	{
		printer->path = vec_get(&pathset->paths, i++);
		if (printer->path->ants > 0)
		{
			printer->path->ants--;
			printer->ant_number++;
			send_ant(printer);
		}
	}
	printer->start_line++;
}

int	print_solution(t_pathset *pathset)
{
	t_printer	printer;

	if (printer_init(&printer, pathset) == ERROR)
		return (printer_free(&printer), ERROR);
	while (has_ants_to_send(pathset))
		send_ant_wave(&printer, pathset);
	vec_iter(&printer.lines, put_line);
	return (printer_free(&printer), OK);
}
