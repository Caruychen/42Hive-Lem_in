/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djb2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:20:15 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/05 17:21:33 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// Performs djb2-hashing of a node based on its alias.
size_t	node_hash(t_hashtable *htable, t_flow_node *node)
{
	return (str_hash(htable, node->alias));
}

// Performs djb2-hashing of a string.
size_t	str_hash(t_hashtable *htable, char *str)
{
	size_t	hash;

	hash = 5381;
	while (*str)
	{
		hash = ((hash << 5) + hash) + *str;
		str++;
	}
	return (hash % (htable->alloc_size / htable->elem_size));
}
