/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:02:07 by cchen             #+#    #+#             */
/*   Updated: 2022/01/01 23:48:59 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static char	*ft_traverse_str(char *s1)
{
	while (*s1)
		++s1;
	return (s1);
}

char	*ft_strcat(char *s1, const char *s2)
{
	char	*temp;

	temp = ft_traverse_str(s1);
	ft_strcpy(temp, s2);
	return (s1);
}
