/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:30:10 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/08 16:04:42 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	r_rotate(t_stack stack)
{
	t_stack_node	*last;
	int				tmp;

	if (!stack.size)
		return ;
	last = find_last_node(stack);
	tmp = last->data;
	while (last->previous)
	{
		last->data = last->previous->data;
		last = last->previous;
	}
	last->data = tmp;
}

void	rra(t_stack *stack_a, int bool)
{
	r_rotate(*stack_a);
	if (bool)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack_b, int bool)
{
	r_rotate(*stack_b);
	if (bool)
		ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int bool)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_printf("rrr\n");
}
