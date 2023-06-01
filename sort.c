/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:02:10 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/01 17:14:56 by cdurro           ###   ########.fr       */
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

int	is_sorted(t_stack stack)
{
	if (!stack.size)
		return (1);	
	while (stack.stack->next != NULL)
	{
		if (stack.stack->data > stack.stack->next->data)
			return (0);
		stack.stack = stack.stack->next;
	}
	return (1);
}

int	smallest_data(t_stack stack)
{
	int	min;

	min = INT_MAX;
	while (stack.stack)
	{
		if (stack.stack->data < min)
			min = stack.stack->data;
		stack.stack = stack.stack->next;
	}
	return (min);
}

int	highest_data(t_stack stack)
{
	int max;

	max = INT_MIN;
	while (stack.stack)
	{
		if (stack.stack->data > max)
			max = stack.stack->data;
		stack.stack = stack.stack->next;
	}
	return (max);
}

void	tiny_sort(t_stack *stack)
{
	int	highest;
	
	if (!stack->size)
		return ;
	highest = highest_data(*stack);
	if (is_sorted(*stack))
		return ;
	if (stack->stack->data == highest)
		ra(stack, 1);
	else if (stack->stack->next->data == highest)
		rra(stack, 1);
	if (stack->stack->data > stack->stack->next->data)
		sa(stack, 1);
}
// 3	6
// 4		
// 5
// 9
void	push_smallest(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest;
	int mid;
	int pos;

	smallest = smallest_data(*stack_a);
	mid = stack_a->size / 2;
	pos = get_node_pos(*stack_a, smallest);

	while (stack_a->stack->data != smallest)
	{
		if (pos > mid)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	pb(stack_a, stack_b);
}

void	five_sort(t_stack *stack_a, t_stack *stack_b)
{
	print_stack(*stack_a, 1);

	if (stack_a->size > 4)
		push_smallest(stack_a, stack_b);
	push_smallest(stack_a, stack_b);
		
	tiny_sort(stack_a);

	while (stack_b->size)
		pa(stack_b, stack_a);
	update_index(*stack_a);

	print_stack(*stack_a, 1);
}

int min_size(t_stack stack_a, t_stack stack_b, int pos_a, int pos_b)
{
	if (stack_a.size < stack_b.size)
		return (stack_a.size - pos_a - 1);
	else
		return (stack_b.size - pos_b - 1);
}

void	calculate_cost(t_stack stack_a, t_stack stack_b, int current_max, int current_min, int current_num)
{
	int i;
	int pos_a;
	int pos_b;
	int size;

	i = 0;

	pos_a = get_node_pos(stack_a, current_num);
	pos_b = get_node_pos(stack_b, current_max);

	if (pos_a < stack_a.size - 1 && pos_b < stack_b.size - 1
		&& pos_a >= stack_a.size / 2 && pos_b >= stack_b.size / 2)
	{
			size = min_size(stack_a, stack_b, pos_a, pos_b);
			while (size--)
			{
				stack_a.stack->cost[i++] = 5;
				pos_a++;
				pos_b++;
			}
			while (pos_a != stack_a.size - 1)
			{
				stack_a.stack->cost[i++] = 5;
				pos_a++;
			}
			while (pos_b != stack_b.size - 1)
			{
				stack_a.stack->cost[i++] = 5;
				pos_b++;
			}
			
	}


	int i = 0;
	while (stack_a.stack->cost[i])
	{
		printf("command: %i", stack_a.stack->cost[i]);
		i++;
	}

}

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	int max;
	int	min;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);

	// do while till 3 numbers are left in stack a
	// while (stack_a->size > 3)
	// {
		max = highest_data(*stack_b);
		min = smallest_data(*stack_b);
		calculate_cost(*stack_a, *stack_b, max, min, stack_a->stack->data);
	// }

}
