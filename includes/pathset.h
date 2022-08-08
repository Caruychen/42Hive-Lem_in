/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:56:03 by cchen             #+#    #+#             */
/*   Updated: 2022/08/04 15:02:08 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSET_H
# define PATHSET_H

typedef struct s_path
{
	t_vec		nodes;	
	size_t		ants;
	size_t		height;
}				t_path;

int			path_new(t_path *path);
t_flow_node	*path_get(t_path *path, size_t index);
int			path_fill(t_path *path, size_t index, t_trace trace,
				t_flow_network *network);
void		path_free(t_path *path);

typedef struct s_pathset
{
	t_vec	paths;
	size_t	ants;
	size_t	steps;
	size_t	total_nodes;
}				t_pathset;

int			pathset_init(t_pathset *pathset, size_t n_paths, size_t n_ants);
int			pathset_fill(t_pathset *pathset, t_trace trace,
				t_flow_network *network);
int			pathset_from_network(t_pathset *pathset, t_flow_network *network,
				t_bfs_utils *bfs_utils);
t_path		*pathset_get(t_pathset *pathset, size_t index);
void		pathset_free(t_pathset *pathset);

void		pathset_keep_best(t_pathset *pathset);
void		pathset_assign_ants(t_pathset *pathset);

#endif
