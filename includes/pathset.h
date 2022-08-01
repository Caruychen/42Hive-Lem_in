/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:56:03 by cchen             #+#    #+#             */
/*   Updated: 2022/08/01 22:59:47 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSET_H
# define PATHSET_H

typedef struct	s_path
{
	t_vec		nodes;	
	size_t		ants;
}				t_path;

typedef struct	s_pathset
{
	t_vec	paths;
	size_t	ants;
	size_t	steps;
}				t_pathset;

int		pathset_init(t_pathset *pathset, size_t n_paths, size_t n_ants);
void	pathset_free(t_pathset *pathset);

#endif
