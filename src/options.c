/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:25:23 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/17 13:56:59 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	set_option(t_options *options, char *arg)
{
	char	*sample;
	char	*res;

	sample = "qav";
	res = ft_strchr(sample, *arg++);
	if (!res || *arg)
		return (error(MSG_ERROR_INV_OPTION));
	options->flags = res + 1 - sample;
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
	return (OK);
}
