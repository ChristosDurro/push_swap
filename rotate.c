/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:59:49 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/09 15:04:16 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rotate(t_stack stack)
{
	int				tmp;

	if (!stack.size)
		return ;
	tmp = stack.stack->data;
	while (stack.stack->next)
	{
		stack.stack->data = stack.stack->next->data;
		stack.stack = stack.stack->next;
	}
	stack.stack->data = tmp;
}

void	ra(t_stack *stack_a, int bool)
{
	rotate(*stack_a);
	if (bool)
		ft_printf("ra\n");
}

void	rb(t_stack *stack_b, int bool)
{
	rotate(*stack_b);
	if (bool)
		ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}
