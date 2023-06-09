/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:35:47 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/08 16:03:27 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack_node	*smallest(t_stack stack)
{
	t_stack_node	*min;

	min = stack.stack;
	while (stack.stack)
	{
		if (stack.stack->data < min->data)
			min = stack.stack;
		stack.stack = stack.stack->next;
	}
	return (min);
}

t_stack_node	*highest(t_stack stack)
{
	t_stack_node	*max;

	max = stack.stack;
	while (stack.stack)
	{
		if (stack.stack->data > max->data)
			max = stack.stack;
		stack.stack = stack.stack->next;
	}
	return (max);
}

t_stack_node	*find_target_pos(t_stack stack_b, int current_num)
{
	t_stack_node	*higher_node;
	int				higher;

	higher = INT_MAX;
	while (stack_b.stack)
	{
		if (stack_b.stack->data > current_num)
		{
			if (stack_b.stack->data < higher)
			{
				higher = stack_b.stack->data;
				higher_node = stack_b.stack;
			}
		}
		stack_b.stack = stack_b.stack->next;
	}
	return (higher_node);
}

t_stack_node	*get_num(t_stack stack, int index)
{
	int	i;

	i = stack.size - 1 - index;
	while (i != stack.stack->pos)
	{
		stack.stack = stack.stack->next;
	}
	return (stack.stack);
}

t_stack_node	*find_last_node(t_stack head)
{
	if (!head.size)
		return (NULL);
	while (head.stack->next)
		head.stack = head.stack->next;
	return (head.stack);
}
