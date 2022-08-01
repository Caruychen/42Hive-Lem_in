/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:47:54 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/02 01:05:50 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "vec.h"

static int	printer_init(t_printer *printer, t_pathset *pathset)
{
	size_t	i;
	t_vec	line;

	*printer = (t_printer){0};
	if (vec_new(&printer->lines, pathset->steps, sizeof (t_vec)) == ERROR)
		return (ERROR);
	if (vec_from(&printer->move, "L\0", 2, sizeof (char)) == ERROR)
		return (ERROR);
	i = 0;
	/* line = (t_vec){.elem_size = sizeof (char)}; */
	while (i < pathset->steps)
	{
		/* vec_new(&line, pathset->flow, sizeof (char)); */
		vec_new(&line, 64, sizeof (char));
		vec_push(&printer->lines, &line);
		i++;
	}
	return (OK);
}

static void	update_move_prefix(t_printer *printer)
{
	char	*number_string;

	printer->move.len = 1;
	number_string = ft_itoa(printer->ant_number);
	if (!number_string)
		return ;
	vec_append_str(&printer->move, number_string);
	ft_strdel(&number_string);
	vec_append_strn(&printer->move, "-", 1);
}

static void	send_ant(t_printer *printer, t_flow_network *network)
{
	size_t	i;
	size_t	node_id;
	size_t	dash_id;
	t_vec	*line;

	update_move_prefix(printer);
	dash_id = printer->move.len;
	i = 1;
	while (i < printer->path->nodes.len)
	{
		printer->move.len = dash_id;
		node_id = *(size_t *)vec_get(&printer->path->nodes, i);
		vec_append_str(&printer->move, network_get(network, node_id)->alias);
		line = vec_get(&printer->lines, printer->start_line + i - 1);
		vec_append_str(line, printer->move.memory);
		vec_append_strn(line, " ", 1);
		i++;
	}
}

static void	send_ant_wave(t_printer *printer, t_pathset *pathset,
	t_flow_network *network)
{
	size_t	i;

	i = 0;
	while (i < pathset->paths.len)
	{
		printer->path = vec_get(&pathset->paths, i);
		if (printer->path->ants > 0)
		{
			printer->path->ants--;
			printer->ant_number++;
			send_ant(printer, network);
		}
		i++;
	}
	printer->start_line++;
}

static int	has_ants_to_send(t_pathset *pathset)
{
	static t_path	*shortest_path;

	if (!shortest_path)
		shortest_path = vec_get(&pathset->paths, 0);
	return (shortest_path->ants > 0);
}

static void	put_line(void *line)
{
	char	*str;

	str = ((t_vec *)line)->memory;
	str[((t_vec *)line)->len - 1] = '\0';
	ft_putstr(((t_vec *)line)->memory);
	ft_putchar('\n');
}

int	print(t_flow_network *network, t_pathset *pathset)
{
	t_printer	printer;

	if (printer_init(&printer, pathset) == ERROR)
		return (ERROR);
	while (has_ants_to_send(pathset))
	{
		send_ant_wave(&printer, pathset, network);
	}
	vec_iter(&printer.lines, put_line);
	return (OK);
}
