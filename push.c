/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:54:47 by cdurro            #+#    #+#             */
/*   Updated: 2023/05/25 13:22:09 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node *push_node;
	if (!(*src))
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	push_node->previous = NULL;
	if (!(*dest))
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->previous = push_node;
		*dest = push_node;
	}
	
}

void	pa(t_stack_node **src, t_stack_node **dest)
{
	push(src, dest);
	ft_printf("pa\n");
}

void	pb(t_stack_node **src, t_stack_node **dest)
{
	push(src, dest);
	ft_printf("pb\n");
}
