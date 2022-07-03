/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:40:03 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/03 19:40:38 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

#include "lem_in.h"

typedef t_vec t_hashtable;

size_t	hash_func(t_hashtable *htable, char *str);
int		hashtable_from(t_hashtable *dst, t_vec *src);
int		hashtable_insert(t_hashtable *dst, char *alias);
void	*hashtable_get(t_hashtable *src, char *alias);
int	vec_insert(t_vec *dst, void *src, size_t index);

#endif
