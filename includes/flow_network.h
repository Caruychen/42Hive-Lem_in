/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_network.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:28:29 by cchen             #+#    #+#             */
/*   Updated: 2022/06/07 14:48:07 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOW_NETWORK_H
# define FLOW_NETWORK_H

t_vec	*network_init(void);
int		network_push(t_flow_node node);
int		network_add_edge(t_vec network, t_flow_edge edge);

#endif
