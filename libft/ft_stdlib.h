/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:35:07 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 13:27:21 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdlib.h>
# define HEX_STR_L "0123456789abcdef"
# define HEX_STR_U "0123456789ABCDEF"
# define MAX_LL_STR_SIZE 33

int		ft_atoi(const char *str);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int value, int base, int uppercase);
char	*ft_ultoa(uintmax_t value, int base, int uppercase);
char	*ft_ltoa(intmax_t value, int base);
void	ft_memdelarray(void ***arr);
void	ft_strdelarray(char ***arr);
void	ft_swap(int *a, int *b);
void	ft_swap_ul(unsigned long *a, unsigned long *b);

#endif
