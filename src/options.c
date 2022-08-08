/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:25:23 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/02 20:26:48 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	options_init(t_options *options, int argc, char **argv)
{
	int	i;

	*options = (t_options){FALSE};
	if (argc == 1)
		return (OK);
	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-q"))
			options->quiet = TRUE;
		else if (!ft_strcmp(argv[i], "-v"))
			options->verbose = TRUE;
		else
			return (ERROR);
		i++;
	}
	return (OK);
}
