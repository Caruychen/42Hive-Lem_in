/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:04:58 by cchen             #+#    #+#             */
/*   Updated: 2022/06/26 20:41:00 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "flow_edge.h"
# include "flow_node.h"
# include "flow_network.h"
# include "parser.h"

# define OK 1
# define TRUE 1
# define FALSE 0
# define ERROR -1

int	parse_input(void);
int	error(char *msg);

#endif
