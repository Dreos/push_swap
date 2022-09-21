/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:00:40 by lloisel           #+#    #+#             */
/*   Updated: 2022/09/21 18:12:05 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_part(t_lc *current)
{
	t_lc *tmp;

	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;		
	}
}

void	free_ldc(t_ldc *a)
{
	t_ldc *tmp;
	
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;	
	}
}
	
void	free_all(t_stack *a, t_stack *b, t_lc *part)
{
	if (a)
	{
		free_ldc(a->first);
		free(a);
	}
	if (part)
	{
		free_part(part);	
	}
	if (b)
	{
		free_ldc(b->first);
		free(b);
	}
}
/*
void display_lc(t_lc *l)
{
	while(l)
	{
		printf("bot :%d top :%d \n",l->min,l->max);
		l= l->next;
	}
}
void display_ldc(t_ldc *a)
{
	while (a)
	{
		printf("%d ",a->value);
		a = a->next;
	}
	printf("\n");
}

void display_stack(t_stack *s)
{
	printf("________\n");
	display_ldc(s->first);
	
}*/
t_ldc	*check_all(int argc, char **argv, t_ldc *a)
{
	if(!check_arg(argc,argv))
		return(error("arg wrong\n"), NULL);
	a = create_stack(argv, a);
	if(!check_duplicate(a))
	{
		free_ldc(a);
		return(error("duplicate\n"), NULL);
	}
	return(a); 
}
void	big_sort(t_stack *sta, t_stack *stb, t_lc *part)
{
	while(part)
	{
		push_to_b(sta,stb, part->min, part->max);		
		part = part->next;
	}
	while(stb->first)
	{
		update_min_max(stb);
		put_on_top(stb, stb->max, 'b');
		push_to_a(sta, stb, stb->first);
	}
}

void	sort(t_ldc *a)
{
	t_stack	*sta;
	t_stack	*stb;
	t_lc	*part;

	sta = initiate_stack(a);
	stb = initiate_stack(NULL);
	part = NULL;
	update_min_max(sta);
	if(!is_sorted(sta))
	{	
		if(sta->size < 6)
			little_sort(sta, stb);
		else if(sta->size <= 200)
		{
			part = generate_partitions(sta, 8, sta->min->value, sta->max->value);
			big_sort(sta, stb, part);
		}
		else
		{
			part = generate_partitions(sta, 16, sta->min->value, sta->max->value);
			big_sort(sta, stb, part);
		}	
	}
	free_all(sta, stb, part);	
}
int main(int argc, char **argv)
{
	t_ldc	*a;

	a = NULL;	
	a = check_all(argc, argv, a);
	if (a)
		sort(a);
	return (0);	
}
