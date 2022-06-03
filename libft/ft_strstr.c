/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:04:06 by cchen             #+#    #+#             */
/*   Updated: 2022/01/06 11:14:46 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_is_match(const char *hay_piece, const char *needle)
{
	while (1)
	{
		if (*needle == 0)
			return (1);
		if (*hay_piece++ != *needle++)
			return (0);
	}
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack != *needle)
		{
			++haystack;
			continue ;
		}
		if (ft_is_match(haystack, needle))
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}	
