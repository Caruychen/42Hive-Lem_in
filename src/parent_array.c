/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:23:34 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/20 10:59:11 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "vec.h"

// Creates an array of the size of n (number of nodes in the graph)
// filled with -1's and a -2 for the source.
int	parent_array_reset(t_vec *network, long source_id, t_vec *parent_array)
{
	size_t	i;

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

// Uses the parent_array to create an array containing only the path indices.
// The path goes backwards, from sink to source.
int	parent_array_get_path(t_vec *parent_array, t_vec *path, long sink_id)
{
	long	id;

	id = sink_id;
	while (1)
	{
		if (vec_push(path, &id) == ERROR)
			return (ERROR);
		id = *(long *)vec_get(parent_array, id);
		if (id == -2)
			break ;
		if (id == -1)
			return (ERROR);
	}
	return (OK);
}
