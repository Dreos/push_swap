/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:25:35 by lloisel           #+#    #+#             */
/*   Updated: 2022/09/19 05:57:32 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rev_r(t_stack *s)
{
	t_ldc *tmp;
	
	if(s->size >= 2)
	{
		tmp = s->last;
		s->last  = s->last->prev;
		s->last->next = NULL;
		tmp->next = s->first;
		tmp->prev = NULL;
		s->first->prev = tmp;
		s->first = tmp;
	}
}
void rra(t_stack *s)
{
	rev_r(s);
	write(1,"rra\n",4);
}

void rrb(t_stack *s)
{
	rev_r(s);	
	write(1,"rrb\n",4);
}

void rrr(t_stack *a , t_stack *b)
{
	rev_r(a);
	rev_r(b);
	write(1,"rrr\n",4);
}
