/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:25:30 by lloisel           #+#    #+#             */
/*   Updated: 2022/09/19 05:59:03 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void rot(t_stack *s)
{
	t_ldc *tmp;
	
	if (s->size >= 2)
	{
		tmp = s->first;
		s->first  = s->first->next;
		s->first->prev = NULL;
		s->last->next = tmp;
		tmp->prev = s->last;
		tmp->next = NULL;
		s->last = tmp;
	}
}
void ra(t_stack *s)
{
	rot(s);
	write(1,"ra\n",3);
}

void rb(t_stack *s)
{
	rot(s);
	write(1,"rb\n",3);
}
void rr(t_stack *a , t_stack *b)
{
	rot(a);
	rot(b);
	write(1,"rr\n",3);
}
