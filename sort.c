/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:02:10 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/13 16:55:47 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack *stack)
{
	t_stack_node	*max;

	if (!stack->size)
		return ;
	max = highest(*stack);
	if (is_sorted(*stack))
		return ;
	if (stack->stack->data == max->data)
		ra(stack, 1);
	else if (stack->stack->next->data == max->data)
		rra(stack, 1);
	if (stack->stack->data > stack->stack->next->data)
		sa(stack, 1);
}

void	push_smallest(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*min;
	int				mid;
	int				pos;

	min = smallest(*stack_a);
	mid = stack_a->size / 2;
	pos = get_node_pos(*stack_a, min->data);
	while (min->pos != stack_a->size - 1)
	{
		if (pos > mid)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
		min = smallest(*stack_a);
	}
	pb(stack_a, stack_b);
}

void	five_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	if (stack_a->size > 4)
		push_smallest(stack_a, stack_b);
	push_smallest(stack_a, stack_b);
	tiny_sort(stack_a);
	while (stack_b->size)
		pa(stack_b, stack_a);
	update_index(*stack_a, *stack_b);
}


void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*num;
	int				i;
	int				j;
	int				*best;

	while (stack_a->size)
	{
		best = ft_calloc(stack_a->size + stack_b->size + 1, sizeof(int));
		if (!best)
			return ;
		i = -1;
		while (++i < stack_a->size)
		{
			num = get_num(*stack_a, i);
			num->cost = ft_calloc(stack_a->size + stack_b->size + 1, sizeof(int));
			j = 0;
			calculate_stack_a(stack_a, i, &j, num);
			calculate_stack_b(stack_b, &j, num);
			update_list(num->cost);
			check_best(num->cost, best);
			free(num->cost);
		}
		execute_commands(best, stack_a, stack_b);
	}
	rotate_max_on_top_and_push(stack_a, stack_b);
	// free_all(stack_a);

}
