/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:38:18 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/05 18:05:06 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static int	hashtable_update_element(t_hashtable *dst, void *src, size_t index)
{
	ft_memcpy(&dst->memory[dst->elem_size * index], src, dst->elem_size);
	return (OK);
}

int	hashtable_put_node(t_hashtable *dst, t_flow_node *src, size_t orig_index)
{
	t_flow_node	*node;
	size_t		index;

	if (!dst || !src || !dst->memory)
		return (ERROR);
	if (orig_index >= dst->len)
		return (error(MSG_ERR_HASH_OVER));
	index = orig_index;
	while (index < dst->len)
	{
		node = vec_get(dst, index);
		if (!node->alias)
			return (hashtable_update_element(dst, src, index));
		index++;
	}
	index = 0;
	while (index < orig_index)
	{
		node = vec_get(dst, index);
		if (!node->alias)
			return (hashtable_update_element(dst, src, index));
		index++;
	}
	return (error(MSG_ERR_HASHTABLE_FULL));
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
		if (node->alias && !ft_strcmp(node->alias, alias))
			return (node);
		index++;
	}
	index = 0;
	while (index < orig_index)
	{
		node = vec_get(src, index);
		if (node->alias && !ft_strcmp(node->alias, alias))
			return (node);
		index++;
	}
	return (NULL);
}
