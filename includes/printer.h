/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:03:06 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/02 13:30:40 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include "lem_in.h"

typedef struct s_printer
{
	t_vec	lines;
	t_path	*path;
	t_vec	move;
	int		ant_number;
	size_t	start_line;
	size_t	dash_id;
}	t_printer;

int	print_solution(t_flow_network *network, t_pathset *pathset);
int	has_ants_to_send(t_pathset *pathset);

#endif
