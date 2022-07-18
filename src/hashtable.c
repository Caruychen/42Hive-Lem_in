/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:56:41 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/18 23:00:07 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "lem_in.h"

int	hashtable_from(t_hashtable *dst, t_vec *src)
{
	int	index;

	if (!dst || !src)
		return (ERROR);
	if (vec_new(dst, src->len * 1.33, sizeof(int)) == ERROR)
		return (ERROR);
	ft_memset(dst->memory, -1, dst->alloc_size);
	dst->len = dst->alloc_size / dst->elem_size;
	index = 0;
	while (index < src->len)
	{
		hashtable_put_node(dst, index, node_hash(dst, vec_get(src, index)));
		index++;
	}
	return (OK);
}

static int	hashtable_update_element(t_hashtable *dst, int network_index, size_t index)
{
	ft_memcpy(&dst->memory[dst->elem_size * index], &network_index, dst->elem_size);
	return (OK);
}

long	hashtable_get_node_index(t_hashtable *src, char *alias)
{
	size_t		index;
	size_t		orig_index;
	t_flow_node	*node;

	if (!alias || !src)
		return (ERROR);
	orig_index = str_hash(src, alias);
	index = 0;
	while (index < src->len)
	{
		hash_index = orig_index + index - (src->len * (orig_index + index >= src->len));
		hash_value = *(int *)vec_get(src, hash_index);
		if (hash_value >= 0 && !ft_strcmp(node->alias, alias))
			return (hash_value);
		index++;
	}
	return (ERROR);
}

int	hashtable_put_node(t_hashtable *dst, int network_index, size_t orig_index)
{
	int	hash_value;
	size_t	index;
	size_t	hash_index;

	if (!dst || !dst->memory)
		return (ERROR);
	if (orig_index >= dst->len)
		return (error(MSG_ERR_HASH_OVER));
	index = 0;
	while (index < dst->len)
	{
		hash_index = orig_index + index - (dst->len * (orig_index + index >= dst->len));
		hash_value = *(int *)vec_get(dst, hash_index);
		if (hash_value < 0)
			return (hashtable_update_element(dst, network_index, hash_index));
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
