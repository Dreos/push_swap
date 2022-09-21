/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_set_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:15:14 by lloisel           #+#    #+#             */
/*   Updated: 2022/09/21 15:20:45 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void update_min_max(t_stack *s)
{
	t_ldc *min;
	t_ldc *max;
	t_ldc *current;

	current = s->first;
	min = s->first;
	max = s->first;
	while(current)
	{
		if( current->value > max->value)
			max = current;
		if( current->value < min->value)
			min = current;
		current = current->next;
	}
	s->min = min;
	s->max = max;
}
int lowest(int a, int b)
{
	if(a >= b)
		return (b);
	return(a);
}

int tte(t_ldc *current)
{
	int i;

	i = 0;
	while(current)
	{
		current = current->next;
		i++;
	}
	return(i);
}
t_ldc *get_target(t_stack *s)
{
	int min;
	int max;

	min = lowest(tte(s->min),tte(s->min)- s->size);
	max = lowest(tte(s->max),tte(s->max)- s->size);
	if(min <= max)
		return(s->min);
	return(s->max);
}

void push_to_a(t_stack *a ,t_stack *b ,t_ldc *t)
{
	if (t->value == b->max->value)
	{
		push_a(a,b);
	}
	else
	{
		
		push_a(a,b);
		ra(a);
	}
}

void put_on_top(t_stack *s , t_ldc *t,char c)
{	
	if( tte(t) >= s->size/2 + 1)
	{
		while(s->first->value != t->value)
		{
			if(c == 'a')
				ra(s);
			else
				rb(s);
		}	
	}
	else
	{
		while(s->first->value != t->value)
		{
			if(c == 'a')
				rra(s);
			else
				rrb(s);
		}
	}
}

int nft(t_stack *s, int min,  int max)
{
	while(s->first)
	{
		if(s->first->value <= max && s->first->value>= min)
			return(1);
		s->first = s->first->next;
	}
	return(0);
}
t_ldc *best_push(t_stack *s,int min , int max)
{
	t_ldc *rt;
	int old;
	int tmp;

	rt = NULL;
	while(s->first)
	{
		if(s->first->value >= min && s->first->value <= max)
		{
			if(!rt)
				rt = s->first;	
			tmp = lowest(tte(s->first),tte(s->first)- s->size);
			old = lowest(tte(rt),tte(rt)-s->size);
			if(tmp < old)
				rt = s->first;
		}
		s->first = s->first->next;
	}
	return(rt);
}

void push_to_b(t_stack *a,t_stack *b,int min , int max)
{
	int i;

	i = a->size;	

	while(i > 0)
	{	
		if(a->first)
		{
			if(a->first->value >= min && a->first->value <= max)
			{
				push_b(a,b);
			}
			else
				ra(a);
		}	
		i--;
	}
}
