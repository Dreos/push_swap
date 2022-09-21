/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:16:21 by lloisel           #+#    #+#             */
/*   Updated: 2022/09/21 18:06:51 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_duplicate(t_ldc *current)
{
	t_ldc *tmp;
		
	tmp = current;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (tmp->value == current->value)
				return (0);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (1);
}

int is_number(char *s)
{
	if (*s == '-' || *s == '+' )
		s++;
	while (*s)
	{	
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	check_arg(int argc , char** argv)
{
	int	i;
	int 	j;
	char**	tmp;

	i = 1;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');	
		while (tmp[j])
		{	
			if (!is_number(tmp[j]))
			{
				free_split(tmp);
				return (0);
			}
			j++;
		}
		i++;	
		free_split(tmp);
	}
	return (1);
}

t_ldc	*add_to_stack(t_ldc *current, int i)
{
	t_ldc	*tmp;
	t_ldc	*c;

	c = current;
	tmp = (t_ldc *)malloc(sizeof(t_ldc));
	if (!tmp)
		return (NULL);
	tmp->value = i;
	if (!current)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		return (tmp);
	}
	while (c->next)
		c = c->next;
	c->next = tmp;
	tmp->next = NULL;
	tmp->prev = c;
	return (current);
}

t_ldc	*create_stack(char **argv, t_ldc *current)
{
	char	**tmp;
	int	i;
	int	j;
	long int	test;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
		{
			test = ft_atoi(tmp[j]);
			if (test > 2147483647 || test < -2147483648)
			{
				free_split(tmp);
				free_ldc(current);
				return (error("Arg wrong"), NULL);
			}
			current = add_to_stack(current, test);
			j++;
		}
		free_split(tmp);
	}
	return (current);
}
