/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:02:31 by cdurro            #+#    #+#             */
/*   Updated: 2023/05/25 13:27:30 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


void	swap(t_stack_node **head)
{
	if (!(*head))
		return ;
	*head = (*head)->next;
	(*head)->previous->previous = *head;
	(*head)->previous->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->previous = (*head)->previous;
	(*head)->next = (*head)->previous;
	(*head)->previous = NULL;
}

void	sa(t_stack_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	// ft_printf("ss\n");
}
