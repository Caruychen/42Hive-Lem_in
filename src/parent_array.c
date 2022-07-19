/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:23:34 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/19 15:23:48 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// Creates an array of the size of n (number of nodes in the graph)
// filled with -1's and a -2 for the source.
int	parent_array_init(t_vec *network, long source_id, t_vec *parent_array)
{
	size_t	i;

	if (vec_new(parent_array, network->len, sizeof(long)) == ERROR)
		return (ERROR);
	parent_array->len = network->len;
	i = 0;
	while (i < parent_array->len)
	{
		((long *)parent_array->memory)[i] = -1;
		i++;
	}
	((long *)parent_array->memory)[source_id] = -2;
	return (OK);
}

void	parent_array_update(t_vec *parent_array, size_t id, long value)
{
	((long *)parent_array->memory)[id] = value;
}

int	has_no_parent(t_vec *parent_array, long id)
{
	return (*((long *)vec_get(parent_array, id)) == -1);
}

