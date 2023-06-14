/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:02:31 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/09 15:05:45 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack *head)
{
	int	tmp;

	if (!head->size)
		return ;
	tmp = head->stack->data;
	head->stack->data = head->stack->next->data;
	head->stack->next->data = tmp;
}

void	sa(t_stack *stack_a, int bool)
{
	swap(stack_a);
	if (bool)
		ft_printf("sa\n");
}

void	sb(t_stack *stack_b, int bool)
{
	swap(stack_b);
	if (bool)
		ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}
