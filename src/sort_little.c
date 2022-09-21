/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:23:32 by lloisel           #+#    #+#             */
/*   Updated: 2022/09/21 18:12:04 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first  = a->first->value;
	second  = a->first->next->value;
	third	= a->first->next->next->value;
	if ( first > second && second < third && first < third)
		sa(a);
	else if ( first > second && second > third && first > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);	
	else if ( first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}	
	else if ( first < second && second > third && first > third)
		rra(a);
}

void	sort_under_six(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push_b(a, b);	
	sort_three(a);
	while (b->first)
	{
		update_min_max(a);
		if (b->first->value > a->max->value)
		{
			push_a(a, b);
			ra(a);
		}
		else
			push_a(a, b);
	}
}

void	sort_two(t_stack *a)
{
	if (!is_sorted(a))
		ra(a);
}
void little_sort(t_stack *a,t_stack *b)
{
	if (a->size <= 1)
	{
		return;
	}
	if (a->size == 2)
	{
		sort_two(a);
	}
	if (a->size == 3)
	{
		sort_three(a);
	}
	if (a->size > 3)
	{
		sort_under_six(a, b);
	}
}
