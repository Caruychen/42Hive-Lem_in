/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:03:10 by cchen             #+#    #+#             */
/*   Updated: 2022/01/06 11:13:10 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stdlib.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	length;

	length = ft_strlen(s1);
	new = ft_strnew(length);
	if (!new)
		return (NULL);
	new = ft_memcpy(new, s1, length + 1);
	return (new);
}
