/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:02:10 by cdurro            #+#    #+#             */
/*   Updated: 2023/05/25 13:27:56 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// void	merge(t_stack *stack_a, t_stack *stack_b, t_stack *stack_tmp)
// {
// 	printf("Before merge while loop\n");
// 	while (!is_empty(stack_a) && !is_empty(stack_b))
// 	{
// 		printf("Comparing %d and %d\n", stack_a->numbers[stack_a->top], stack_b->numbers[stack_b->top]);
// 		if (stack_a->numbers[stack_a->top] < stack_b->numbers[stack_b->top])
// 			push(stack_tmp, pop(stack_a));
// 		else
// 			push(stack_tmp, pop(stack_b));
// 	}
// 	printf("After merge while loop\n");
// 	while (!is_empty(stack_a))
// 		push(stack_tmp, pop(stack_a));

// 	while (!is_empty(stack_b))
// 		push(stack_tmp, pop(stack_b));
	
// 	while (!is_empty(stack_tmp))
// 		push(stack_a, pop(stack_tmp));
// }
#include<limits.h>

int	is_sorted(t_stack_node *stack)
{
	int	i;

	if (!stack)
		return (1);	
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack_node	*smallest_node(t_stack_node *stack)
{
	int				min;
	t_stack_node	*min_node;

	min = INT_MAX;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*highest_node(t_stack_node *stack)
{
	int max;
	t_stack_node	*max_node;

	max = INT_MIN;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	tiny_sort(t_stack_node **stack)
{
	t_stack_node	*highest;

	highest = highest_node(*stack);
	if (!(*stack))
		return ;
	if (is_sorted(*stack))
		return ;
	if (*stack == highest)
		ra(stack);
	else if ((*stack)->next == highest)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

void	my_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int mid;
	t_stack_node *highest;
	t_stack_node *smallest;

	if (stack_b == NULL)
	{
		push(stack_a, stack_b);
		push(stack_a, stack_b);
	}
	while (stack_a)
	{
		highest = highest_node(*stack_b);
		smallest = smallest_node(*stack_b);
		if ((*stack_a)->data > highest->data)
		{
			while (*stack_b != highest)
			{
				if (highest->above_mid)
					rb(stack_b);
				else
					rrb(stack_b);
			}
			pb(stack_a, stack_b);
		}
		else if ((*stack_a)->data < smallest->data)
		{
			while (*stack_b != smallest)
			{
				if (smallest->above_mid)
					rb(stack_b);
				else
					rrb(stack_b);
			}
			pb(stack_a, stack_b);
		}
		else if ((*stack_a)->data < highest->data && (*stack_a)->data > smallest->data)
		{
			while ((*stack_a)->data < highest->next->data)
			{
				highest = highest->next;
				rb(stack_b);
			}
			pb(stack_a, stack_b);
		}
		*stack_a = (*stack_a)->next;
	}
	highest = highest_node(*stack_b);
	while(*stack_b != highest)
	{
		if (highest->above_mid)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	while (stack_b)
		pa(stack_b, stack_a);
}

// void	get_target_node(t_stack_node *stack_a, t_stack_node *stack_b)
// {
// 	t_stack_node	*current_a;	
// 	t_stack_node	*target_node;
// 	long			match_index;

// 	while (stack_b)
// 	{
// 		match_index = 2147483647;
// 		current_a = stack_a;
// 		while (current_a)
// 		{
// 			if (current_a->data > stack_b->data && current_a->data < match_index)
// 			{
// 				match_index = current_a->data;
// 				target_node = current_a;
// 			}
// 			current_a = current_a->next;
// 		}
// 		if (match_index == 2147483647)
// 			target_node = smallest_node(stack_a);
// 		else
// 			stack_b->target_node = target_node;
// 		stack_b = stack_b->next;
// 	}
		
// }

// void	set_cost(t_stack_node *stack_a, t_stack_node *stack_b)
// {
// 	int	len_a;
// 	int	len_b;

// 	len_a = stack_len(stack_a);
// 	len_b = stack_len(stack_b);
// 	while (stack_b)
// 	{
// 		stack_b->push_price = stack_b->pos;
// 		if (!(stack_b->above_mid))
// 			stack_b->push_price = len_b - stack_b->pos;
// 		if (stack_b->target_node->above_mid)
// 			stack_b->push_price += stack_b->target_node->pos;
// 		else
// 			stack_b->push_price += len_a - stack_b->target_node->pos;
// 		stack_b = stack_b->next;
// 	}
// }
