/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:12:34 by cchen             #+#    #+#             */
/*   Updated: 2022/08/01 15:50:34 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	pathset_init(t_pathset *pathset, size_t n_paths, size_t n_ants)
{
	t_path	path;

	if (vec_new(&pathset->paths, n_paths, sizeof(t_path)) == ERROR)
		return (ERROR);
	while (n_paths > 0)
	{
		if (vec_new(&path.nodes, 1, sizeof(size_t)) == ERROR)
			return (pathset_free(pathset), ERROR);
		if (vec_push(&pathset->paths, &path) == ERROR)
			return (vec_free(&pathset->paths), ERROR);
		n_paths--;
	}
	pathset->ants = n_ants;
	return (OK);
}

void	pathset_free(t_pathset *pathset)
{
	size_t	index;
	t_path	*path;

	index = 0;
	while (index < pathset->paths.len)
	{
		path = (t_path*) vec_get(&pathset->paths, index);
		vec_free(&path->nodes);
		index++;
	}
	vec_free(&pathset->paths);
}