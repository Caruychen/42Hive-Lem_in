/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:28:44 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 14:41:24 by cchen            ###   ########.fr       */
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


#endif
