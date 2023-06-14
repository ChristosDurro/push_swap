/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:58:43 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/09 14:48:50 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	place_new_min(t_stack stack_b, int *list, int index)
{
	t_stack_node	*min;
	int				i;

	min = smallest(stack_b);
	i = min->pos;
	if (i > stack_b.size / 2)
	{
		while (i++ < stack_b.size - 1)
		{
			list[index++] = RB;
		}
		list[index++] = RB;
	}
	else
	{
		while (i-- > 0)
			list[index++] = RRB;
	}
	list[index++] = PB;
}

void	place_new_max(t_stack stack_b, int *list, int index)
{
	t_stack_node	*max;
	int				i;

	max = highest(stack_b);
	i = max->pos;
	if (i > stack_b.size / 2)
	{
		while (i++ < stack_b.size - 1)
			list[index++] = RB;
	}
	else
	{
		while (i-- >= 0)
			list[index++] = RRB;
	}
	list[index++] = PB;
}

void	place_between(t_stack stack_b, int num, int *list, int index)
{
	t_stack_node	*next_highest;
	int				i;

	next_highest = find_target_pos(stack_b, num);
	i = next_highest->pos;
	if (i > stack_b.size / 2)
	{
		while (i++ <= stack_b.size - 1)
			list[index++] = RB;
	}
	else
	{
		while (i-- > 0)
			list[index++] = RRB;
	}
	list[index++] = PB;
}
