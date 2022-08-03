/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:13:07 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/03 10:58:04 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	error(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (ERROR);
}

int	main_free(int res, t_flow_network *network, t_pathset *pathset)
{
	network_free(network);
	pathset_free(pathset);
	return (res);
}
