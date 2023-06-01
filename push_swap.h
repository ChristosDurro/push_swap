/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:55:31 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/01 16:38:17 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include"libft/libft.h"
#include"ft_printf/ft_printf.h"

# define SA 0
# define SB 1
# define SS 2
# define RA 3
# define RB 4
# define RR 5
# define RRA 6
# define RRB 7
# define RRR 8
# define PA 9
# define PB 10
// # define  0


typedef struct s_stack_node
{
	int					data;
	int					pos;
	int					*cost;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}		t_stack_node;




typedef struct s_stack
{
	t_stack_node	*stack;
	int				size;
}		t_stack;

int		is_empty(t_stack_node **stack);
int		is_full(t_stack_node **stack);
int		check_params(int ac, char **av);
int		check_digits(int ac, char **av);
int		check_dupes(int ac, char **av);
int		check_limit(int ac, char **av);
int 	count_args(char **av);
int		get_node_pos(t_stack stack, int	target);
int		highest_data(t_stack stack);
int		smallest_data(t_stack stack);

void	push(t_stack *src, t_stack *dest);
void	pa(t_stack *src, t_stack *dest);
void	pb(t_stack *src, t_stack *dest);

void	rotate(t_stack stack);
void	ra(t_stack *stack_a, int bool);
void	rb(t_stack *stack_b, int bool);
void	rr(t_stack *stack_a, t_stack *stack_b, int bool);

void	r_rotate(t_stack stack);
void	rra(t_stack *stack_a, int bool);
void	rrb(t_stack *stack_b, int bool);
void	rrr(t_stack *stack_a, t_stack *stack_b, int bool);

void	swap(t_stack *stack);
void	sa(t_stack *stack_a, int bool);
void	sb(t_stack *stack_b, int bool);

void	ft_initiailise(t_stack *stack, char **av, int ac);

void	print_stack(t_stack stack, int bool);
void	update_index(t_stack stack);


t_stack_node *find_last_node(t_stack head);

void	tiny_sort(t_stack *stack);
void	five_sort(t_stack *stack_a, t_stack *stack_b);
void	big_sort(t_stack *stack_a, t_stack *stack_b);

#endif
