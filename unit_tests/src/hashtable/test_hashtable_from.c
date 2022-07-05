/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashtable_from.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:50:10 by cnysten           #+#    #+#             */
/*   Updated: 2022/07/05 19:33:27 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	is_in_hashtable(t_hashtable *htable, const char *alias)
{
	size_t		i;
	t_flow_node	*node;

	i = 0;
	while (i < htable->len)
	{
		node = vec_get(htable, i);
		if (node && node->alias && !ft_strcmp(alias, node->alias))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void	test_one_node(void)
{
	t_vec		network;
	t_hashtable	htable = {0};
	int			ret;

	if (!network_init(&network))
		return ;
	if (!network_add_node(&network, ft_strdup("zazaa")))
		return ;
	ret = hashtable_from(&htable, &network);
	assert(ret == OK);
	assert(htable.elem_size == sizeof (t_flow_node));
	assert(htable.len == 1);
	assert(is_in_hashtable(&htable, "zazaa") == TRUE);
	network_free(&network);
	network_free(&htable);
}

static void	test_three_nodes(void)
{
	t_vec		network;
	t_hashtable	htable = {0};
	int			ret;

	if (!network_init(&network))
		return ;
	if (!network_add_node(&network, ft_strdup("abc")))
		return ;
	if (!network_add_node(&network, ft_strdup("def")))
		return ;
	if (!network_add_node(&network, ft_strdup("ghi")))
		return ;
	ret = hashtable_from(&htable, &network);
	assert(ret == OK);
	assert(htable.elem_size == sizeof (t_flow_node));
	assert(htable.len == 3);
	assert(is_in_hashtable(&htable, "abc") == TRUE);
	assert(is_in_hashtable(&htable, "def") == TRUE);
	assert(is_in_hashtable(&htable, "ghi") == TRUE);
	network_free(&network);
	network_free(&htable);
}

static void	test_empty_vec(void)
{
	t_vec		network;
	t_hashtable	htable = {0};
	int			ret;

	if (!network_init(&network))
		return ;
	ret = hashtable_from(&htable, &network);
	assert(ret == ERROR);
	network_free(&network);
	network_free(&htable);
}

static void	test_null_vec(void)
{
	t_vec		network;
	t_hashtable	htable = {0};
	int			ret;

	ret = hashtable_from(&htable, &network);
	assert(ret == ERROR);
	network_free(&network);
	network_free(&htable);
}

void	test_hashtable_from(void)
{
	ft_printf("Testing hashtable_from: ");

	test_one_node();
	test_three_nodes();
	test_empty_vec();
	test_null_vec();

	ft_printf("OK\n");
}
