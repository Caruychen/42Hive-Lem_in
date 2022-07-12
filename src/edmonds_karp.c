/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:11:32 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/12 11:39:00 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	path_init(t_vec *path)
{
	return (vec_new(path, 1, sizeof(long)));
}

static int	bfs(t_vec *network, t_info *info, t_vec *path)
{
	(void) network;
	(void) info;
	(void) path;
	return (OK);
}

int	edmonds_karp(t_vec *network, t_info *info, t_vec *paths)
{
	int		flow;
	t_vec	path;

	(void) paths;
	info->max_flow = 0;
	while (TRUE)
	{
		if (path_init(&path) == ERROR)
			return (ERROR);
		flow = bfs(network, info, &path);
		if (flow == 0)
			break ;
		info->max_flow += flow;
		//TODO: iterate through path, set flow for each edge in the path
		//TODO: while iterating through path keep track of which nodes are in paths
		// and which nodes are not
	}
	return (OK);
}
