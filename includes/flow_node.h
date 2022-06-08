/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_node.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:47:39 by cchen             #+#    #+#             */
/*   Updated: 2022/06/08 15:16:56 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOW_NODE_H
# define FLOW_NODE_H

typedef struct	s_flow_node {
	char	*alias;
	t_vec	edges;
}				t_flow_node;

t_flow_node	node_make(char *alias);
int		node_add_edge(t_flow_node *node, t_flow_edge **edge);
void		node_free(t_flow_node *node);

#endif
