/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_array.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:18:54 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/20 15:15:06 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARENT_ARRAY_H
# define PARENT_ARRAY_H

# include "lem_in.h"
# include "libft.h"

int		parent_array_reset(t_vec *network, long source_id, t_vec *parent_array);
void	parent_array_update(t_vec *parent_array, size_t id, long value);
int		has_no_parent(t_vec *parent_array, long id);
int		parent_array_get_path(t_vec *parent_array, t_vec *path, long sink_id);

#endif
