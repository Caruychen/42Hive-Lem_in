/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:03:06 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/17 16:19:15 by cchen            ###   ########.fr       */
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

int		printer_init(t_printer *printer, t_pathset *pathset);
void	printer_free(t_printer *printer);
int		has_ants_to_send(t_pathset *pathset);
void	put_line(void *ptr);
void	update_move_prefix(t_printer *printer);
void	print_analysis(t_pathset pathset);
int		print_result(t_pathset *pathset, t_vec *inputs, t_options options);

#endif
