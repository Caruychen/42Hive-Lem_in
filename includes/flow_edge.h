/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_edge.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:06:08 by cchen             #+#    #+#             */
/*   Updated: 2022/06/08 14:55:25 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOW_EDGE_H
# define FLOW_EDGE_H

#include <stdint.h>

typedef struct s_flow_edge
{
	int	from;
	int	to;
	uint8_t	flow: 1;
}				t_flow_edge;

t_flow_edge	*edge_make(int from, int to);
int			edge_other(t_flow_edge *edge, int node);
int			edge_has_residual_capacity_to(t_flow_edge *edge, int node);
void		edge_augment_flow_to(t_flow_edge *edge, int node);
void		edge_free(t_flow_edge *edge);

#endif
