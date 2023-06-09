/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:09:52 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/09 13:26:57 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	calculate_stack_a(t_stack *stack_a, int i, int *j, t_stack_node *num)
{
	if (stack_a->size - 1 - i >= stack_a->size / 2)
	{
		while (*j != i && i != stack_a->size - 1)
			num->cost[(*j)++] = RA;
	}
	else
	{
		while (stack_a->size - 1 - i - *j >= 0)
			num->cost[(*j)++] = RRA;
	}
}

void	calculate_stack_b(t_stack *stack_b, int *j, t_stack_node *num)
{
	if (num->data < smallest(*stack_b)->data)
		place_new_min(*stack_b, num->cost, *j);
	else if (num->data > highest(*stack_b)->data)
		place_new_max(*stack_b, num->cost, *j);
	else
		place_between(*stack_b, num->data, num->cost, *j);
}
