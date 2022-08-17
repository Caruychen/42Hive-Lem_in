/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:10:11 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/17 14:01:39 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define MSG_USAGE "Usage: ./lem-in\n  -q, quiet mode\n  -v, verbose mode\n \
 -a, analysis mode\n"

typedef enum e_option
{
	QUIET = 1,
	ANALYSIS,
	VERBOSE
}	t_option;

typedef struct s_options
{
	uint8_t	flags: 2;
}	t_options;

int	options_init(t_options *options, int argc, char **argv);

#endif
