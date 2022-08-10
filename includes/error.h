/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:35:19 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/10 10:23:08 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define MSG_ERROR_INV_FILE "ERROR: File missing ant number, rooms or links."
# define MSG_ERROR_INV_LINE "ERROR: File contained an invalid line."
# define MSG_ERROR_INV_LINK "ERROR: File contained an invalid link input"
# define MSG_ERROR_GNL "ERROR: Could not get next line."
# define MSG_ERROR_CHAR_ALIAS "ERROR: Invalid character in room alias."
# define MSG_ERROR_MALLOC_VLINK "ERROR: Memory allocation failed."
# define MSG_ERROR_MOD "ERROR: Invalid modification."
# define MSG_ERROR_MOD_DUP "ERROR: Duplicated modifier"
# define MSG_ERROR_MOD_MISSING "ERROR: Missing start or end modifier"
# define MSG_ERR_NETWORK_INIT "ERROR: Could not initialize flow network."
# define MSG_ERR_HASH_INIT "ERROR: Could not initialize hashmap."
# define MSG_ERR_HASH_GET "ERROR: Could not get entry from hashmap."
# define MSG_ERROR_NO_ANTS "ERROR: Insufficient ants."
# define MSG_ERROR_NO_PATHS "Sorry, I couldn't find any paths."

int	error(char *msg);
int	main_free(int res, t_flow_network *network, t_pathset *pathset);

#endif
