/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:09:34 by cchen             #+#    #+#             */
/*   Updated: 2022/01/01 23:54:40 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

static void	ft_map(char *res, char const *s, char (*f)(char), size_t size)
{
	while (size--)
		*res++ = f(*s++);
	*res = 0;
}

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	char	*res;

	if (!s)
		return (NULL);
	size = sizeof(*res) * (ft_strlen(s) + 1);
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	ft_map(res, s, f, size - 1);
	return (res);
}
