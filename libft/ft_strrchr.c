/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:46:57 by cchen             #+#    #+#             */
/*   Updated: 2022/01/01 23:57:05 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*latest;
	char	ch;

	latest = (char *)0;
	ch = (char)c;
	while (1)
	{
		if (*s == ch)
			latest = (char *)s;
		if (*s == 0)
			return (latest);
		++s;
	}
}
