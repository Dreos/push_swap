/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:00:58 by lloisel           #+#    #+#             */
/*   Updated: 2022/09/21 17:04:52 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_h
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_lc
{
	int	min;
	int	max;
	struct s_lc	*next;
}	t_lc;

typedef struct s_ldc
{
	int	value;
	struct s_ldc	*next;
	struct s_ldc	*prev;
}	t_ldc;
typedef struct stack
{
	t_ldc	*first;
	t_ldc	*last;
	t_ldc	*min;
	t_ldc	*max;
	int	size;
}	t_stack;

void little_sort(t_stack *a,t_stack *b);
void push_to_a(t_stack *a ,t_stack *b ,t_ldc *t);
void put_on_top(t_stack *s , t_ldc *t,char c);
void push_to_b(t_stack *a,t_stack *b,int min , int max);
t_stack *initiate_stack(t_ldc *current);
void free_ldc(t_ldc *a);
char	**ft_split(const char *s, char c);
void	free_split(char **tab);
int	ft_isdigit(int c);
long int ft_atoi(char *nptr);
int	check_arg(int argc , char** argv);
t_ldc *create_stack(char **argv, t_ldc *current);
int check_duplicate(t_ldc *current);
t_lc *generate_partitions(t_stack *s,int nb,int bot ,int top);
void update_min_max(t_stack *s);
int avg(t_stack *s,int min , int max);

int is_sorted(t_stack *s);
void sa(t_stack *s);
void ss(t_stack *a, t_stack *b);
void sb(t_stack *s);
void push_b(t_stack *a,t_stack *b);
void push_a(t_stack *b,t_stack *a);
void rr(t_stack *a , t_stack *b);
void ra(t_stack *s);
void rb(t_stack *s);
void rrr(t_stack *a , t_stack *b);
void rra(t_stack *s);
void rrb(t_stack *s);
void error(char *s);
t_ldc *get_target(t_stack *s);


#endif 
