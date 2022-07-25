/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:04:36 by cchen             #+#    #+#             */
/*   Updated: 2022/07/26 00:21:27 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOW_STRUCTS_H
# define FLOW_STRUCTS_H

typedef struct s_flow_edge
{
	long		from;
	long		to;
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
}		t_flow_network;

#endif
