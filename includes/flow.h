/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:13:21 by cchen             #+#    #+#             */
/*   Updated: 2022/07/28 14:14:34 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOW_H
# define FLOW_H

typedef struct s_flow_edge
{
	size_t		from;
	size_t		to;
	uint8_t		flow: 1;
}				t_flow_edge;

typedef struct s_flow_node
{
	char	*alias;
	t_vec	edges;
	int		x;
	int		y;
	uint8_t	is_free: 1;
	uint8_t	is_via_augment: 1;
}				t_flow_node;

typedef struct s_flow_network
{
	t_vec	adj_list;
	t_vec	edge_list;
	size_t	source;
	size_t	sink;
	size_t	n_ants;
}		t_flow_network;

#endif
