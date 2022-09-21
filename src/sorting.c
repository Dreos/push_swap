/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:04:37 by lloisel           #+#    #+#             */
/*   Updated: 2022/09/21 14:34:52 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int sizez(t_stack *s,int min,int max)
{
	int size;
	t_ldc *current;

	size = 0;
	current = s->first;
	while(current)
	{
		if(current->value >= min && current->value <= max)
			size = size + 1;
		current = current->next;
	}
	if(size == 0)	
		size = 1;
	return(size);
}
int avg(t_stack *s,int min , int max)
{
	float i;
	t_ldc *current;
	int size;
	float tmp;

	size = sizez(s,min,max);
	current = s->first;
	i = 0;
	while(current)
	{
		if(current->value >= min && current->value <= max)
		{
			tmp = (float)current->value;
			i = i + tmp/(float)size;
		}
		current = current->next;
	}
	return ((int)i);
}

t_lc *create_lc(int min , int max)
{
	t_lc *l;
	
	l = (t_lc *)malloc(sizeof(t_lc));
	if(!l)
		return (NULL);
	l->min = min;
	l->max = max;
	return(l);
}

t_lc *generate_partitions(t_stack *s,int nb,int bot ,int top)
{
	static t_lc *rt;
	t_lc *tmp;
	int mid;

	mid = avg(s,bot,top);
	if(!rt)
		rt = NULL; 
	if(nb <= 2)
	{
		//printf("Bot : %d Top :%d\n",bot,top);
		tmp = create_lc(mid+1,top);
		tmp->next = rt;
		rt = tmp;
		tmp = create_lc(bot,mid);
		tmp->next = rt;
		rt = tmp;
	}
	else
	{	
		generate_partitions(s, nb/2, mid + 1, top);
		generate_partitions(s, nb/2, bot, mid);	
	}
	return(rt);
}
