/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_edge.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:06:08 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 16:30:05 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *   Flow edge represents the link/tunnel between nodes (i.e. rooms).
 *   Edge capacity is capped at 1, making the "flow" state also a
 *   binary state. The flow state is used for the edmunds-karp algorithm.
 *
 *   The flow edge data type:
 *    ------------------
 *   | FROM | TO | FLOW |
 *    ------------------
 * 
 *   Where FROM and TO describe the INDEX of the respective nodes at
 *   both ends. The nodes are part of an indexed array implemented in the
 *   flow_network data type.
 *
 *   NOTE: How we interpret the FLOW as a binary state, is crucial to how
 *   path augmentation is implemented for the edmunds-karp algorithm.
 *   When FLOW = 0:
 *       * There is residual flow available for other direction
 *       * The residual flow is bi-directional
 *       * The directionality of FROM & TO are ignored
 *   When FLOW = 1:
 *       * Residual flow is only available in the direction towards FROM
 *       * The residual flow is directional
 *       * Directionality is embedded into FROM & TO
*/

#ifndef FLOW_EDGE_H
# define FLOW_EDGE_H

# include <stdint.h>
# include "vec.h"

typedef struct s_flow_edge
{
	long		from;
	long		to;
	uint8_t		flow: 1;
}				t_flow_edge;

t_flow_edge	*edge_make(const long from, const long to);
long		edge_other(t_flow_edge *edge, const long node);
int			edge_has_residual_capacity_to(t_flow_edge *edge, const long node);
int			edge_augment_flow_to(t_flow_edge *edge, const long node);
void		edge_free(t_flow_edge **edge);

int			edge_list_make(t_vec *edge_list);
int			edge_list_push(t_vec *edge_list, t_flow_edge *edge);
void		edge_list_free(t_vec *edge_list);
t_flow_edge	*edge_list_get(t_vec *edge_list, size_t index);

#endif
