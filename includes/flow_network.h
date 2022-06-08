/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_network.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:28:29 by cchen             #+#    #+#             */
/*   Updated: 2022/06/08 22:12:42 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOW_NETWORK_H
# define FLOW_NETWORK_H

int		network_init(t_vec *network);
int		network_add_node(t_vec *network, char *alias);
int		network_add_edge(t_vec *network, t_flow_edge *edge);
void	network_free(t_vec *network);

#endif
