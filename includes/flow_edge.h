/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_edge.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:06:08 by cchen             #+#    #+#             */
/*   Updated: 2022/08/17 16:24:14 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               FLOW_EDGE                                    */
/******************************************************************************
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
 *   FLOW is treated as a binary state. This is crucial to how
 *   path augmentation is implemented for the edmunds-karp algorithm.
 *   When FLOW = 0:
 *       * Bi-Directional.
 *       * There is residual capacity towards both directions.
 *       * The directionality of FROM & TO are agnostic
 *   When FLOW = 1:
 *       * Directional.
 *       * There is only residual capacity towards FROM.
 *       * Directionality is embedded into FROM & TO
 *****************************************************************************/

#ifndef FLOW_EDGE_H
# define FLOW_EDGE_H

# include "flow.h"

/* Edge API */
t_flow_edge	*edge_make(const long from, const long to);
long		edge_other(t_flow_edge *edge, const size_t node);
int			edge_has_residual_capacity_to(t_flow_edge *edge, const size_t to,
				t_vec *adj_list);
int			edge_has_flow_to(t_flow_edge *edge, const size_t to,
				t_vec *adj_list);
int			edge_augment_flow_to(t_flow_edge *edge, const size_t to,
				t_flow_network *network);

#endif
