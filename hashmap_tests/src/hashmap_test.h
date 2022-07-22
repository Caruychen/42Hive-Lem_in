/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_test.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:48:27 by cchen             #+#    #+#             */
/*   Updated: 2022/07/22 13:13:08 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_TEST_H
# define HASHMAP_TEST_H

# include <assert.h>
# include <string.h>
# include <limits.h>
# include "hashmap.h"
# include "ft_stdio.h"

void	test_hashmap_create_entry(void);
void	test_hashmap_new_with_capacity(void);
void	test_hashmap_new(void);
void	test_hashmap_insert(void);
void	test_hashmap_try_insert(void);
void	test_hashmap_entry(void);
void	test_hashmap_get(void);
void	test_hashmap_remove(void);

#endif
