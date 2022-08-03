/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:10:11 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/02 20:27:52 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define MSG_USAGE "Usage: ./lem-in\n  -q, quiet mode\n  -v, verbose mode"

typedef struct s_options
{
	uint8_t	quiet;
	uint8_t	verbose;
}	t_options;

int	options_init(t_options *options, int argc, char **argv);

#endif
