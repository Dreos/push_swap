/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:25:46 by lloisel           #+#    #+#             */
/*   Updated: 2022/09/19 06:01:58 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swi(t_stack *s)
{
	int tmp;
			
	if(s->first)
	{
		if(s->first->next)
		{
			tmp  = s->first->value;
			s->first->value = s->first->next->value;
			s->first->next->value = tmp;
		}
	}
}
void sa(t_stack *s)
{
	swi(s);
	write(1,"sa\n",3);
}

void sb(t_stack *s)
{
	swi(s);
	write(1,"sb\n",3);
}

void ss(t_stack *a, t_stack *b)
{
	swi(a);
	swi(b);
	write(1,"ss\n",3);
}
void push_b(t_stack *a,t_stack *b)
{
	t_ldc *tmp;
	
	if (a->first)
	{
		tmp = a->first->next;
		if(b->first)
			b->first->prev = a->first;	
		a->first->next = b->first;
		b->first = a->first;
		if(!b->first->next)
			b->last = b->first;	
		if(tmp)
			tmp->prev = NULL;
		a->first = tmp;
		a->size = a->size - 1;
		b->size = b->size + 1;
	}
	write(1,"pb\n",3);
}

void push_a(t_stack *b,t_stack *a)
{
	t_ldc *tmp;
	
	if (a->first)
	{
		tmp = a->first->next;
		if(b->first)
			b->first->prev = a->first;	
		a->first->next = b->first;
		b->first = a->first;
		if(!b->first->next)
			b->last = b->first;	
		if(tmp)
			tmp->prev = NULL;
		a->first = tmp;
		a->size = a->size - 1;
		b->size = b->size + 1;
	}
	write(1,"pa\n",3);
}
