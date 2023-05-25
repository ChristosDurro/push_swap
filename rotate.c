/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:59:49 by cdurro            #+#    #+#             */
/*   Updated: 2023/05/25 13:27:44 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node *last;
	
	if (!(*stack))
		return ;
	last = find_last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;	
}

void	ra(t_stack_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	// ft_printf("rr\n");
}
