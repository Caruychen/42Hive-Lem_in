/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:35:05 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 16:29:08 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Edge list is primarily used as a utility set of functions.
 * In order to easily clean up data, we maintain a single mother list of
 * all edges in a single array.
 * Once the program closes and cleans up, we iterate through the edge_list
 * to free all edges.
*/

#include "lem_in.h"

int	edge_list_make(t_vec *edge_list)
{
	return (vec_new(edge_list, 1, sizeof(t_flow_edge *)));
}

int	edge_list_push(t_vec *edge_list, t_flow_edge *edge)
{
	return (vec_push(edge_list, (void *) &edge));
}

t_flow_edge	*edge_list_get(t_vec *edge_list, size_t index)
{
	return (*(t_flow_edge **)vec_get(edge_list, index));
}

void	edge_list_free(t_vec *edge_list)
{
	size_t	index;

	index = 0;
	while (index < edge_list->len)
		edge_free(&(edge_list->memory[edge_list->elem_size * index++]));
	vec_free(edge_list);
}
