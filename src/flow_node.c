/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:04:24 by cchen             #+#    #+#             */
/*   Updated: 2022/06/08 15:29:38 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_flow_node node_make(char *alias)
{
	t_flow_node node;

	node.alias = alias;
	vec_new(&(node.edges), 1, sizeof(t_flow_edge *));
	return (node);
}

/* This may or may not work, since vec_push expects a single void * pointer */
int	node_add_edge(t_flow_node *node, t_flow_edge *edge)
{
	return (vec_push(&(node->edges), (void *) &edge));
}

void	node_free(t_flow_node *node)
{
	if (node->alias != NULL)
		ft_strdel(&(node->alias));
	if (node->edges.memory != NULL)
		vec_free(&(node->edges));
}
