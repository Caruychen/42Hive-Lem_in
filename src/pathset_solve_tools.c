/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset_solve_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:40:55 by cchen             #+#    #+#             */
/*   Updated: 2022/08/18 11:13:58 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* Computes the total number of steps required to send all ants through the 
 * pathset. Stores the result in pathset->steps */
static int	compute_steps(t_pathset *pathset)
{
	size_t	index;
	size_t	delta;
	size_t	ants;
	size_t	res;
	t_path	*path;

	ants = pathset->ants;
	res = pathset_get(pathset, 0)->height;
	index = 0;
	while (index < pathset->paths.len)
	{
		path = pathset_get(pathset, ++index);
		if (!path)
			break ;
		if (path->height <= res)
			continue ;
		delta = path->height - res;
		if (index * delta > ants)
			break ;
		ants -= index * delta;
		res += delta;
	}
	res += ants / index + ((ants % index) > 0);
	return (pathset->steps = res, res);
}

/* Returns TRUE or FALSE depending on whether current pathset is better */
static int	is_better(t_pathset *pathset)
{
	static size_t	cost;
	size_t			res;

	if (pathset->paths.len == 1)
	{
		cost = pathset->ants + pathset->total_nodes;
		pathset->steps = cost;
		return (TRUE);
	}
	res = compute_steps(pathset);
	if (res < cost)
		return (cost = res, TRUE);
	return (FALSE);
}

/* Determines whether the given pathset requires fewer steps to send ants 
 * If better, then free the previous pathset and save the given pathset.
 * Otherwise, free the given pathset and replace with the previous best
 * pathset. */
void	pathset_keep_best(t_pathset *pathset)
{
	static t_pathset	best;

	if (is_better(pathset))
	{
		pathset_free(&best);
		best = *pathset;
		return ;
	}
	pathset_free(pathset);
	*pathset = best;
}

/* Assign residual number of ants to paths */
static void	assign_residual(t_pathset *pathset, size_t len, size_t ants)
{
	size_t	index;
	t_path	*path;

	pathset->steps++;
	index = 0;
	while (index < len && ants > 0)
	{
		path = pathset_get(pathset, index++);
		path->ants++;
		ants--;
	}
}

/* Assign ants to each respective path, given the number of total ants and
 * computed steps */
void	pathset_assign_ants(t_pathset *pathset)
{
	size_t	ants;
	size_t	index;
	size_t	len;
	t_path	*path;

	ants = pathset->ants;
	len = pathset->paths.len;
	index = 0;
	while (index < len && ants > 0)
	{
		path = pathset_get(pathset, index++);
		if (path->height > pathset->steps)
		{
			assign_residual(pathset, len, ants);
			break ;
		}
		path->ants = pathset->steps - path->height;
		if (path->ants > ants)
			path->ants = ants;
		ants -= path->ants;
	}
	pathset->steps--;
}
