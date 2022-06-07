/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:04:24 by cchen             #+#    #+#             */
/*   Updated: 2022/06/07 16:24:48 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_flow_node *node_make(char *alias)
{
	t_flow_node *node;

	node = (t_flow_node *)ft_memalloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->alias = alias;
	if (vec_new(&(node->edges), 1, sizeof(t_flow_edge *)) == ERROR)
		ft_memdel(&node);
	return (node);
}

int	node_add_edge(t_flow_node *node, t_flow_edge **edge)
{
	return (vec_push(&(node->edges), edge));
}
