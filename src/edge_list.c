/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:35:05 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 11:40:29 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	edge_list_make(t_vec *edge_list)
{
	return (vec_new(edge_list, 1, sizeof(t_flow_edge *)));
}

int	edge_list_push(t_vec *edge_list, t_flow_edge *edge)
{
	return (vec_push(edge_list, (void *) &edge));
}

void	edge_list_free(t_vec *edge_list)
{
	size_t	index;

	index = 0;
	while (index < edge_list->len)
		edge_free(&(edge_list->memory[edge_list->elem_size * index++]));
	vec_free(edge_list);
}
