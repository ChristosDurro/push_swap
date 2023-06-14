/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:34:15 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/13 18:40:55 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check_rr_rrr(t_operations *commands, int *list, int *i)
{
	while (commands->ra > 0 && commands->rb > 0)
	{
		list[(*i)++] = RR;
		commands->ra--;
		commands->rb--;
	}	
	while (commands->rra > 0 && commands->rrb > 0)
	{
		list[(*i)++] = RRR;
		commands->rra--;
		commands->rrb--;
	}
}

void	check_ra_rra(t_operations *commands, int *list, int *i)
{
	while (commands->ra)
	{
		list[(*i)++] = RA;
		commands->ra--;
	}
	while (commands->rra)
	{
		list[(*i)++] = RRA;
		commands->rra--;
	}
}

void	check_rb_rrb(t_operations *commands, int *list, int *i)
{
	while (commands->rb)
	{
		list[(*i)++] = RB;
		commands->rb--;
	}
	while (commands->rrb)
	{
		list[(*i)++] = RRB;
		commands->rrb--;
	}
}
