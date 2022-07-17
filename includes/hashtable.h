/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:40:03 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/17 17:09:38 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

#include "lem_in.h"

# define MSG_ERR_HASH_OVER "Hash value out of bounds."
# define MSG_ERR_HASHTABLE_FULL "Hashtable full, couldn't add element."

typedef t_vec t_hashtable;

size_t		str_hash(t_hashtable *htable, char *str);
size_t		node_hash(t_hashtable *htable, t_flow_node *node);
int			hashtable_from(t_hashtable *dst, t_vec *src);
int			hashtable_put_node(t_hashtable *dst, t_flow_node *node, size_t index);
t_flow_node	*hashtable_get_node(t_hashtable *src, char *alias);
long		hashtable_get_node_index(t_hashtable *src, char *alias);
int			vec_insert(t_vec *dst, void *src, size_t index);

#endif
