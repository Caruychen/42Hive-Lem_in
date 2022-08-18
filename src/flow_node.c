/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:04:24 by cchen             #+#    #+#             */
/*   Updated: 2022/08/18 11:04:20 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* Allocates memory for and creates a new node */
int	node_make(t_flow_node *node, char *alias, int x, int y)
{
	if (!alias)
		return (error(MSG_ERROR_NODE_ALIAS));
	node->alias = alias;
	node->x = x;
	node->y = y;
	node->is_free = 1;
	node->is_via_augment = 0;
	node->dst_to_start = 0;
	node->dst_to_end = 0;
	return (vec_new(&(node->edges), 1, sizeof(t_flow_edge *)));
}

/* Adds a new connecting edge to the given node */
int	node_push(t_flow_node *node, t_flow_edge *edge)
{
	return (vec_push(&(node->edges), (void *) &edge));
}

/* Returns a pointer to the edge at a given index of the node's edge bag */
t_flow_edge	*node_get(t_flow_node *node, size_t index)
{
	return (*(t_flow_edge **)vec_get(&node->edges, index));
}

/* Frees a node's memory */
void	node_free(t_flow_node *node)
{
	if (node->alias != NULL)
		ft_strdel(&(node->alias));
	if (node->edges.memory != NULL)
		vec_free(&(node->edges));
}
