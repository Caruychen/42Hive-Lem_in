/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:46:26 by cchen             #+#    #+#             */
/*   Updated: 2022/07/21 11:45:44 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Unite test suite for Hashmap implementation
 */

#include <stdlib.h>
#include "hashmap_test.h"

int	main(void)
{
	test_hashmap_create_entry();
	test_hashmap_new_with_capacity();
	test_hashmap_new();
	test_hashmap_insert();
	test_hashmap_try_insert();
	system("leaks test_hashmap");
	return (0);
}
