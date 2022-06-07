/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_edge.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:06:08 by cchen             #+#    #+#             */
/*   Updated: 2022/06/07 14:27:56 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOW_EDGE_H
# define FLOW_EDGE_H

typedef struct s_flow_edge
{
	int	from;
	int	to;
	int	flow: 1;
}				t_flow_edge;

t_flow_edge	*edge_make(int from, int to);
int			edge_other_vertex(t_flow_edge *edge, int vertex);
int			edge_residual_capacity_to(t_flow_edge *edge, int vertex);
void		edge_set_flow_to(t_flow_edge *edge, int vertex);
void		edge_unset_flow_to(t_flow_edge *edge, int vertex);

#endif
