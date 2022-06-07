/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_node.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:47:39 by cchen             #+#    #+#             */
/*   Updated: 2022/06/07 16:23:05 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOW_NODE_H
# define FLOW_NODE_H

typedef struct	s_flow_node {
	char	*alias;
	t_vec	edges;
}				t_flow_node;

t_flow_node *flow_make(char *alias);

#endif
