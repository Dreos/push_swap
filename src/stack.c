/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:19:49 by lloisel           #+#    #+#             */
/*   Updated: 2022/09/20 10:14:53 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
int is_sorted(t_stack *s)
{
	t_ldc *current;

	current = s->first;
	while (current && current->next)
	{
		if(current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
t_stack *initiate_stack(t_ldc *current)
{
	int i;
	t_stack *s;

	i = 0;	
	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->min = NULL;
	s->max = NULL;
	if(!current)
	{
		s->first = NULL;
		s->last = NULL;
		s->size = 0;
	}
	s->first = current;
	while(current)
	{
		i++;
		if (!current->next)
			s->last = current;
		current = current->next;
	}
	s->size = i;	
	return(s);
}
