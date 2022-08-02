/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:56:03 by cchen             #+#    #+#             */
/*   Updated: 2022/08/02 12:08:53 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSET_H
# define PATHSET_H

typedef struct s_path
{
	t_vec		nodes;	
	size_t		ants;
}				t_path;

int		path_new(t_path *path);
int		path_fill(t_path *path, size_t index, t_trace trace);

typedef struct s_pathset
{
	t_vec	paths;
	size_t	ants;
	size_t	steps;
}				t_pathset;

int		pathset_init(t_pathset *pathset, size_t n_paths, size_t n_ants);
int		pathset_fill(t_pathset *pathset, t_trace trace);
int		pathset_from_network(t_pathset *pathset, t_flow_network *network,
			t_bfs_utils *bfs_utils);
t_path	*pathset_get(t_pathset *pathset, size_t index);
void	pathset_free(t_pathset *pathset);

#endif
