/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:15:55 by cchen             #+#    #+#             */
/*   Updated: 2022/08/02 16:42:45 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	solve(t_flow_network *network, t_pathset *pathset)
{
	t_bfs_utils	bfs_utils;

	bfs_init(&bfs_utils, network, 0);
	while (network_has_augmenting_path(network, &bfs_utils))
	{
		network_augment(network, bfs_utils.trace);
		if (pathset_from_network(pathset, network, &bfs_utils) == ERROR)
			return (ERROR);
		pathset_select(pathset);
	}
	pathset_trim(pathset);
	pathset_assign_ants(pathset);
	bfs_free(&bfs_utils);
	return (OK);
}
