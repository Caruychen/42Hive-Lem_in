/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:47:54 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/17 14:03:47 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		node = path_get(printer->path, printer->path->nodes.len - i - 1);
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
		printer->path = pathset_get(pathset, i++);
		if (printer->path->ants > 0)
		{
			printer->path->ants--;
			printer->ant_number++;
			send_ant(printer);
		}
	}
	printer->start_line++;
}

static int	print_solution(t_pathset *pathset)
{
	t_printer	printer;

	if (printer_init(&printer, pathset) == ERROR)
		return (printer_free(&printer), ERROR);
	while (has_ants_to_send(pathset))
		send_ant_wave(&printer, pathset);
	vec_iter(&printer.lines, put_line);
	return (printer_free(&printer), OK);
}

int	print_result(t_pathset *pathset, t_vec *inputs, t_options options)
{
	write(1, inputs->memory, inputs->len);
	vec_free(inputs);
	if (options.flags == QUIET)
		return (ft_printf("Solved with %i steps.\n", (int) pathset->steps), 0);
	if (options.flags & ANALYSIS)
		print_analysis(*pathset);
	if (options.flags == ANALYSIS)
		return (0);
	if (print_solution(pathset) == ERROR)
		return (ERROR);
	return (0);
}
