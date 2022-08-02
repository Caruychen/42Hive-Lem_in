/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:28:44 by cchen             #+#    #+#             */
/*   Updated: 2022/08/02 11:47:33 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include "libft.h"
# include "lem_in.h"
# include "pathset.h"
# include <assert.h>
# include <limits.h>

int		test_flow_edge(void);
void	test_edge_make(void);
void	test_edge_other(void);
void	test_edge_has_residual_capacity_to(void);
void	test_edge_augment_flow_to(void);

void	test_edge_list(void);
void	test_edge_list_make(void);
void	test_edge_list_push(void);

void	test_parser(void);
void	test_parse_ant_number(void);
void	test_parse_room(void);
void	test_parse_link(void);

void	test_bfs(void);
void	test_bfs_search(void);

void	test_printer(void);
void	test_print_solution(void);

#endif
