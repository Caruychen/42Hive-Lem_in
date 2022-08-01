/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:56:03 by cchen             #+#    #+#             */
/*   Updated: 2022/08/01 15:40:03 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSET_H
# define PATHSET_H

typedef struct	s_path
{
	t_vec		nodes;	
}				t_path;

typedef struct	s_pathset
{
	t_vec	paths;
	size_t	ants;
}				t_pathset

#endif
