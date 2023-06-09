/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:42:10 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/09 14:34:47 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	list_len(int *list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

void	list_reset(int *list)
{
	int	i;
	int	len;

	i = 0;
	len = list_len(list);
	while (i < len)
	{
		list[i] = 0;
		i++;
	}
}

void	print_list(int *list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		printf("[%i]", list[i]);
		i++;
	}
	printf("\n");
}

void	update_list(int *list)
{
	t_operations	commands;
	int				i;

	i = 0;
	initialise_operations(&commands);
	while (i < list_len(list))
	{
		if (list[i] == RA)
			commands.ra += 1;
		else if (list[i] == RB)
			commands.rb += 1;
		else if (list[i] == RRA)
			commands.rra += 1;
		else if (list[i] == RRB)
			commands.rrb += 1;
		i++;
	}
	list_reset(list);
	i = 0;
	check_rr(&commands, list, &i);
	check_rrr(&commands, list, &i);
	check_ra_rra(&commands, list, &i);
	check_rb_rrb(&commands, list, &i);
	list[i++] = PB;
}
