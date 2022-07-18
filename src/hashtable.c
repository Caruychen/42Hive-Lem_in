/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:56:41 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/18 15:51:02 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "lem_in.h"

int	hashtable_from(t_hashtable *dst, t_vec *src)
{
	size_t		network_index;
	t_flow_node	*node;

	if (!dst || !src)
		return (ERROR);
	if (vec_new(dst, src->len * 1.33, src->elem_size) == ERROR)
		return (ERROR);
	ft_bzero(dst->memory, dst->alloc_size);
	dst->len = dst->alloc_size / dst->elem_size;
	network_index = 0;
	while (network_index < src->len)
	{
		node = vec_get(src, network_index);
		hashtable_put_node(dst, network_index, node_hash(dst, node));
		network_index++;
	}
	return (OK);
}

static int	hashtable_update_element(t_hashtable *dst, void *src, size_t index)
{
	ft_memcpy(&dst->memory[dst->elem_size * index], src, dst->elem_size);
	return (OK);
}

static size_t	probe(size_t *start, size_t end, t_hashtable *htable, char *alias)
{
	size_t		index;
	t_flow_node	*node;

	index = *start;
	while (index < end)
	{
		node = vec_get(htable, index);
		if (alias && node->alias && ft_strcmp(node->alias, alias))
				return (*start = index);
		if (!alias && !node)
				return (*start = index);
		index++;
	}
	return (*start = index);
}

long	hashtable_get_node_index(t_hashtable *src, char *alias)
{
	size_t		index;
	size_t		orig_index;
	t_flow_node	*node;

	if (!alias || !src)
		return (ERROR);
	orig_index = str_hash(src, alias);
	index = orig_index;
	if (probe(&index, src->len, src, alias) < src->len)
		return (index);
	index = 0;
	if (probe(&index, orig_index, src, alias) < orig_index)
		return (index);
	return (ERROR);
}

int	hashtable_put_node(t_hashtable *dst, size_t network_index, size_t orig_index)
{
	size_t		index;

	if (!dst || !dst->memory)
		return (ERROR);
	if (orig_index >= dst->len)
		return (error(MSG_ERR_HASH_OVER));
	index = orig_index;
	while (index < dst->len)
	{
		if (!vec_get(dst, index)->alias)
			return (hashtable_update_element(dst, network_index, index));
		index++;
	}
	index = 0;
	while (index < orig_index)
	{
		if (!vec_get(dst, index)->alias)
			return (hashtable_update_element(dst, network_index, index));
		index++;
	}
	return (error(MSG_ERR_HASHTABLE_FULL));
}

t_flow_node	*hashtable_get_node(t_hashtable *src, char *alias)
{
	long		index;

	if (!alias || !src)
		return (NULL);
	index = hashtable_get_node_index(src, alias);
	if (index == ERROR)
		return (NULL);
	return (vec_get(src, index));
}
