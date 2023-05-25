/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:55:31 by cdurro            #+#    #+#             */
/*   Updated: 2023/05/25 15:03:03 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include"libft/libft.h"
#include"ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					data;
	int					pos;
	int					push_price;
	int					above_mid;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}		t_stack_node;


int		pop(t_stack_node **stack);
int		is_empty(t_stack_node **stack);
int		is_full(t_stack_node **stack);
int		check_params(int ac, char **av);
int		check_digits(int ac, char **av);
int		check_dupes(int ac, char **av);
int		check_limit(int ac, char **av);
int 	count_args(char **av);



void	push(t_stack_node **src, t_stack_node **dest);
void	pa(t_stack_node **stack_a, t_stack_node **stack_b);
void	pb(t_stack_node **stack_a, t_stack_node **stack_b);

void	rotate(t_stack_node **stack);
void	ra(t_stack_node **stack_a);
void	rb(t_stack_node **stack_b);
void	rr();

void	r_rotate(t_stack_node **stack);
void	rra(t_stack_node **stack_a);
void	rrb(t_stack_node **stack_b);
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b);

void	swap(t_stack_node **stack);
void	sa(t_stack_node **stack_a);
void	sb(t_stack_node **stack_b);

void	ft_initiailise(t_stack_node **stack, char **av, int ac);

t_stack_node *find_last_node(t_stack_node *head);

// void	merge_sort(t_stack_node *stack_a, t_stack_node *stack_b, t_stack_node *stack_tmp);
// void	merge(t_stack_node *stack1, t_stack_node *stack2, t_stack_node *stack_tmp);
void	tiny_sort(t_stack_node **stack_a);
void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b);

void	my_sort(t_stack_node **stack_a, t_stack_node **stack_b);






#endif
