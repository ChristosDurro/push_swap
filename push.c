/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:54:47 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/13 14:44:27 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	update_index(t_stack stack_a, t_stack stack_b)
{
	int	pos;

	pos = 0;
	while (stack_a.stack)
	{
		stack_a.stack->pos = stack_a.size - 1;
		stack_a.size--;
		stack_a.stack = stack_a.stack->next;
	}
	pos = 0;
	while (stack_b.stack)
	{
		stack_b.stack->pos = stack_b.size - 1;
		stack_b.size--;
		stack_b.stack = stack_b.stack->next;
	}
}

void	push(t_stack *src, t_stack *dest)
{
	t_stack_node	*push_node;

	if (!src->size)
		return ;
	push_node = src->stack;
	push_node->pos = 0;
	push_node->previous = NULL;
	src->stack = src->stack->next;
	if (src->stack)
		src->stack->previous = NULL;
	if (!dest->size)
	{
		dest->stack = push_node;
		push_node->next = NULL;
	}
	else
	{
		dest->stack->pos += 1;
		push_node->next = dest->stack;
		push_node->next->previous = push_node;
		dest->stack = push_node;
	}
	src->size -= 1;
	dest->size += 1;
	update_index(*src, *dest);
}

void	pa(t_stack *src, t_stack *dest)
{
	push(src, dest);
	ft_printf("pa\n");
}

void	pb(t_stack *src, t_stack *dest)
{
	push(src, dest);
	ft_printf("pb\n");
}
