/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:32:57 by cchen             #+#    #+#             */
/*   Updated: 2022/03/14 16:33:22 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# define FLAGLIST "#0- +"

typedef enum e_flags
{
	HASH = 1,
	ZERO = 2,
	DASH = 4,
	SPACE = 8,
	PLUS = 16,
}	t_flags;

char	*mod_flags(t_specs specs, size_t src_len);

#endif
