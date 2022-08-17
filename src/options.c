/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:25:23 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/17 11:50:29 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static  int	set_option(t_options *options, char *arg)
{
	switch (*arg++)
	{
		case 'q':
			options->flags = QUIET;
			break;
		case 'a':
			options->flags = ANALYSIS;
			break;
		case 'v':
			options->flags = VERBOSE;
			break;
		default:
			return (ERROR);
	}
	if (*arg)
		return (ERROR);
	return (OK);
}

int	options_init(t_options *options, int argc, char **argv)
{
	char	*arg;

	*options = (t_options){FALSE};
	if (argc == 1)
		return (OK);
	if (argc > 2)
		return (error(MSG_ERROR_ONE_OPTION));
	arg = argv[1];
	if (*arg++ != '-')
		return (error(MSG_ERROR_BAD_OPTION));
	if (set_option(options, arg) == ERROR)
		return (ERROR);
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
