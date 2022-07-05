/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:38:18 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/04 16:48:43 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

int	hashtable_from(t_hashtable *dst, t_vec *src)
{
	size_t		i;
	t_flow_node	*node;

	if (!dst || !src)
		return (ERROR);
	if (vec_new(dst, src->len * 1.33, src->elem_size) == ERROR)
		return (ERROR);
	ft_bzero(dst->memory, dst->alloc_size);
	dst->len = dst->alloc_size / dst->elem_size;
	i = 0;
	while (i < src->len)
	{
		node = vec_get(src, i);
		hashtable_put_node(dst, node, node_hash(dst, node));
		i++;
	}
	return (OK);
}

int	hashtable_put_node(t_hashtable *dst, t_flow_node *src, size_t index)
{
	t_flow_node	*node;

	if (!dst || !src || !dst->memory)
		return (ERROR);
	if (index >= dst->len)
		return (error(MSG_ERR_HASH_OVER));
	while (index < dst->len)
	{
		node = vec_get(dst, index);
		if (!node->alias)
			break ;
		index++;
	}
	ft_memcpy(&dst->memory[dst->elem_size * index], src, dst->elem_size);
	return (OK);
}

t_flow_node	*hashtable_get_node(t_hashtable *src, char *alias)
{
	size_t		orig_index;
	size_t		index;
	t_flow_node	*node;

	if (!alias || !src)
		return (NULL);
	orig_index = str_hash(src, alias);
	index = orig_index;
	while (index < src->len)
	{
		node = vec_get(src, index);
		if (!ft_strcmp(node->alias, alias))
			return (node);
		index++;
	}
	index = 0;
	while (index < orig_index)
	{
		node = vec_get(src, index);
		if (!ft_strcmp(node->alias, alias))
			return (node);
		index++;
	}
	return (NULL);
}
