/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:15:55 by cchen             #+#    #+#             */
/*   Updated: 2022/08/16 14:54:48 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	solve(t_flow_network *network, t_pathset *pathset)
{
	t_bfs_utils	bfs_utils;
	size_t		count;

	bfs_init(&bfs_utils, network, 0);
	count = 0;
	while (network_has_augmenting_path(network, &bfs_utils))
	{
		if (network_augment(network, bfs_utils.trace) == ERROR)
			return (error(MSG_ERROR_AUGMENT));
		if (pathset_from_network(pathset, network, &bfs_utils) == ERROR)
			return (ERROR);
		pathset_keep_best(pathset);
		count++;
	}
	if (count == 0)
		return (bfs_free(&bfs_utils), error(MSG_ERROR_NO_PATHS));
	pathset_assign_ants(pathset);
	return (bfs_free(&bfs_utils), OK);
}
