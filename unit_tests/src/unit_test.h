/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:28:44 by cchen             #+#    #+#             */
/*   Updated: 2022/07/04 15:50:33 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include "libft.h"
# include "lem_in.h"
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


void	test_hashtable_from(void);
void	test_hashtable_get_node(void);
void	test_hashtable_put_node(void);
void	test_hashtable(void);

void	test_parser(void);
void	test_get_ant_number(void);
void	test_get_room(void);
void	test_get_link(void);


#endif
