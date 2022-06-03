/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:45:43 by cchen             #+#    #+#             */
/*   Updated: 2022/01/22 18:30:31 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	set_buff(t_vec *buff, size_t index)
{
	if (index == buff->len)
	{
		buff->len = 0;
		return ;
	}
	buff->len = buff->len - (index + 1);
	ft_memcpy(buff->memory, (char *)buff->memory + index + 1, buff->len);
}

static int	push_line(t_vec *buff, char **line, size_t len)
{
	*line = ft_strsub(buff->memory, 0, len);
	if (!*line)
	{
		vec_free(buff);
		return (-1);
	}
	set_buff(buff, len);
	return (1);
}

static long	result(t_vec *buff, char **line, long res, char *nl)
{
	if (res < 0 || (res == 0 && !buff->len))
	{
		vec_free(buff);
		return (res);
	}
	if (nl)
		return (push_line(buff, line, (size_t)(nl - (char *)buff->memory)));
	return (push_line(buff, line, buff->len));
}

static long	read_line(int fd, t_vec *buff, long *res)
{
	if (buff->alloc_size - buff->len < BUFF_SIZE
		&& vec_resize(buff, buff->alloc_size * RESIZE_FACTOR) == -1)
		return (*res = -1);
	return (*res = read(fd, (char *)buff->memory + buff->len, BUFF_SIZE));
}

int	get_next_line(const int fd, char **line)
{
	static t_vec	vectors[FD_MAX];
	t_vec			*buff;
	char			*nl;
	long			res;

	if (fd < 0 || fd >= FD_MAX || !line)
		return (-1);
	buff = &vectors[fd];
	if (!buff->memory && vec_new(buff, BUFF_SIZE, sizeof(char)) == -1)
		return (-1);
	nl = (char *)ft_memchr((char *)buff->memory, '\n', (size_t) buff->len);
	if (nl)
		return ((int) result(buff, line, 1, nl));
	while (read_line(fd, buff, &res) > 0)
	{
		buff->len += (size_t) res;
		nl = ft_memchr((char *)buff->memory + buff->len - res, '\n',
				(size_t) res);
		if (nl)
			break ;
	}
	return ((int) result(buff, line, res, nl));
}
