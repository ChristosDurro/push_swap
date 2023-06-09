/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:57:07 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/09 13:23:45 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check_best(int *list, int *best)
{
	int	len;
	int	j;

	len = list_len(list);
	if (!list_len(best) || len < list_len(best))
	{
		list_reset(best);
		j = 0;
		while (j < len)
		{
			best[j] = list[j];
			j++;
		}
	}
}

void	rotate_max_on_top_and_push(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*max;
	int				i;

	max = highest(*stack_b);
	i = max->pos;
	if (i >= stack_b->size / 2)
	{
		while (i++ < stack_b->size - 1)
			rb(stack_b, 1);
	}
	else
	{
		while (i-- >= 0)
			rrb(stack_b, 1);
	}
	while (stack_b->size)
		pa(stack_b, stack_a);
}

void	execute_commands(int *list, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < list_len(list))
	{
		if (list[i] == RA)
			ra(stack_a, 1);
		else if (list[i] == RB)
			rb(stack_b, 1);
		else if (list[i] == RRA)
			rra(stack_a, 1);
		else if (list[i] == RRB)
			rrb(stack_b, 1);
		else if (list[i] == RR)
			rr(stack_a, stack_b, 1);
		else if (list[i] == RRR)
			rrr(stack_a, stack_b, 1);
		else if (list[i] == PB)
			pb(stack_a, stack_b);
		i++;
	}
	free(list);
}

int	is_sorted(t_stack stack)
{
	if (!stack.size)
		return (1);
	while (stack.stack->next)
	{
		if (stack.stack->data > stack.stack->next->data)
			return (0);
		stack.stack = stack.stack->next;
	}
	return (1);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
