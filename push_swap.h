/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:55:31 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/13 18:41:31 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<stdlib.h>
# include<limits.h>
# include"lib/libft.h"
# include"lib/ft_printf.h"

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

typedef struct s_operations
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_operations;

int				check_params(int ac, char **av, int start);
int				check_digits(int ac, char **av, int start);
int				check_dupes(int ac, char **av, int start);
int				check_limit(int ac, char **av, int start);
int				count_args(char **av);
int				get_node_pos(t_stack stack, int target);
int				list_len(int *list);
int				is_sorted(t_stack stack);

void			push(t_stack *src, t_stack *dest);
void			pa(t_stack *src, t_stack *dest);
void			pb(t_stack *src, t_stack *dest);
void			rotate(t_stack stack);
void			ra(t_stack *stack_a, int bool);
void			rb(t_stack *stack_b, int bool);
void			rr(t_stack *stack_a, t_stack *stack_b);
void			r_rotate(t_stack stack);
void			rra(t_stack *stack_a, int bool);
void			rrb(t_stack *stack_b, int bool);
void			rrr(t_stack *stack_a, t_stack *stack_b);
void			swap(t_stack *stack);
void			sa(t_stack *stack_a, int bool);
void			sb(t_stack *stack_b, int bool);
void			ss(t_stack *stack_a, t_stack *stack_b);
void			ft_initiailise(t_stack *stack, char **av, int ac, int start);
void			print_stack(t_stack stack, int bool);
void			update_index(t_stack stack_a, t_stack stack_b);
void			update_list(int *list);
void			list_reset(int *list);
void			print_list(int *list);
void			tiny_sort(t_stack *stack);
void			five_sort(t_stack *stack_a, t_stack *stack_b);
void			big_sort(t_stack *stack_a, t_stack *stack_b);
void			execute_commands(int *list, t_stack *stack_a, t_stack *stack_b);
void			initialise_operations(t_operations *commands);
void			place_new_max(t_stack stack_b, int *list, int index);
void			place_new_min(t_stack stack_b, int *list, int index);
void			place_between(t_stack stack_b, int num, int *list, int index);
void			check_best(int *list, int *best);
void			rotate_max_on_top_and_push(t_stack *stack_a, t_stack *stack_b);
void			call_sort(t_stack *stack_a, t_stack *stack_b);
void			calculate_stack_a(t_stack *stack_a, int i,
					int *j, t_stack_node *num);
void			calculate_stack_b(t_stack *stack_b, int *j, t_stack_node *num);
void			check_rr_rrr(t_operations *commands, int *list, int *i);
void			check_ra_rra(t_operations *commands, int *list, int *i);
void			check_rb_rrb(t_operations *commands, int *list, int *i);

t_stack_node	*find_last_node(t_stack head);
t_stack_node	*smallest(t_stack stack);
t_stack_node	*highest(t_stack stack);
t_stack_node	*find_target_pos(t_stack stack_b, int current_num);
t_stack_node	*get_num(t_stack stack, int index);

#endif