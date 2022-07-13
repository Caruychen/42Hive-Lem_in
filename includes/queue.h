/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:04:06 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/13 01:16:11 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

/* A queue implementation based on a a dynamic array (t_vec). */
typedef struct s_queue
{
	t_vec	vec;
	size_t	head;
	size_t	tail;
}	t_queue;

int		queue_init(t_queue *queue, size_t elem_size);
int		queue_has_next(t_queue *queue);
int		queue_push(t_queue *queue, void *src);
void	*queue_pop(t_queue *queue);
void	queue_free(t_queue *queue);

#endif
