/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:34:31 by cchen             #+#    #+#             */
/*   Updated: 2022/01/01 23:56:52 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	sub_len;
	char	*substring;

	if (*needle == 0)
		return ((char *)haystack);
	sub_len = ft_strlen(needle);
	substring = (char *)needle;
	while (*haystack && len)
	{
		if (*haystack != *substring)
		{
			++haystack;
			--len;
			continue ;
		}
		if (sub_len > len)
			return (NULL);
		if (!ft_strncmp(haystack, needle, sub_len))
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}
