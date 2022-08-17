/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:56:03 by cchen             #+#    #+#             */
/*   Updated: 2022/08/17 16:19:17 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSET_H
# define PATHSET_H

/* ************************************************************************** */
/*                                  PATH                                      */
/******************************************************************************
 * An individual registered path with flow.
 * Contains a vector of nodes, listed in reverse order. Starts from the end
 * node, to the first node linked to the start node. 
 *
 * Fields:
 *   nodes: path list
 *   ants: number of ants to be sent down path
 *   height: number of rooms
 *****************************************************************************/
typedef struct s_path
{
	t_vec		nodes;	
	size_t		ants;
	size_t		height;
}				t_path;

/* Path API */
int			path_new(t_path *path);
t_flow_node	*path_get(t_path *path, size_t index);
int			path_fill(t_path *path, size_t index, t_trace trace,
				t_flow_network *network);
void		path_free(t_path *path);

/* ************************************************************************** */
/*                                 PATH SET                                   */
/******************************************************************************
 * Holds a vector of all paths that are registered with flow.
 *
 * Fields:
 *    paths: all registered paths
 *    ants: total ants to be sent
 *    steps: total number of steps needed to send all ants
 *    total_nodes: total number of nodes in the path set
 *****************************************************************************/

typedef struct s_pathset
{
	t_vec	paths;
	size_t	ants;
	size_t	steps;
	size_t	total_nodes;
}				t_pathset;

/* Pathset API */
int			pathset_init(t_pathset *pathset, size_t n_paths, size_t n_ants);
int			pathset_from_network(t_pathset *pathset, t_flow_network *network,
				t_bfs_utils *bfs_utils);
t_path		*pathset_get(t_pathset *pathset, size_t index);
void		pathset_free(t_pathset *pathset);

/* Pathset Solve Tools */
void		pathset_keep_best(t_pathset *pathset);
void		pathset_assign_ants(t_pathset *pathset);

#endif
