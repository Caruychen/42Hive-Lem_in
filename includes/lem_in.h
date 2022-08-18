/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:04:58 by cchen             #+#    #+#             */
/*   Updated: 2022/08/18 10:26:00 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/* WELCOME TO THE LEM-IN */

# include "libft.h"

/* FLOW GRAPH OBJECT (DATA STRUCTURES AND API) */
# include "flow_edge.h"
# include "flow_node.h"
# include "flow_network.h"

/* BREADTH FIRST SEARCH UTILITIES AND FUNCTIONS */
# include "bfs.h"

/* PROGRAM SEQUENCE */
/* 1. Parse
 * 2. Solve
 *    i. Save best pathset
 * 3. Print
 */
# include "parser.h"
# include "solve.h"
# include "pathset.h"
# include "printer.h"

/* GENERAL UTILITIES */
# include "error.h"
# include "queue.h"
# include "options.h"

# define OK 1
# define TRUE 1
# define FALSE 0
# define ERROR -1

#endif
