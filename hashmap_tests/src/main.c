/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:46:26 by cchen             #+#    #+#             */
/*   Updated: 2022/07/20 15:27:26 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Unite test suite for Hashmap implementation
 */

#include "hashmap_test.h"

int	main(void)
{
	test_hashmap_new_with_capacity();
	test_hashmap_new();
	test_hashmap_create_entry();
	return (0);
}
