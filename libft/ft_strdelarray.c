/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:18:19 by cchen             #+#    #+#             */
/*   Updated: 2022/01/06 11:09:42 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

void	ft_strdelarray(char ***arr)
{
	char	**temp;

	temp = *arr;
	while (*temp)
		ft_strdel(temp++);
	free(*arr);
	*arr = NULL;
}
