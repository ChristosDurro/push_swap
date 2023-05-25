/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:30:10 by cdurro            #+#    #+#             */
/*   Updated: 2023/05/25 13:23:31 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	r_rotate(t_stack_node **stack)
{
	t_stack_node  *last;

	if (!(*stack))
		return ;
	last = find_last_node(*stack);
	(*stack)->previous = last;
	last->next = *stack;
	last->previous = NULL;
	*stack = (*stack)->next;
	(*stack)->next = NULL;
}

void	rra(t_stack_node **stack_a)
{
	r_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **stack_b)
{
	r_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	// ft_printf("rrr\n");
}
