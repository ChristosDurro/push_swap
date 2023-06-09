/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:19:43 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/09 14:29:20 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
		tiny_sort(stack_a);
	else if (stack_a->size <= 5)
		five_sort(stack_a, stack_b);
	else
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		big_sort(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		start;

	start = 1;
	if (argc == 1 || !argv[1][0])
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = count_args(argv);
		start = 0;
	}
	if (check_params(argc - 1, argv))
	{
		ft_printf("Error!\n");
		return (0);
	}
	ft_initiailise(&a, argv, argc, start);
	ft_initiailise(&b, argv, 0, start);
	call_sort(&a, &b);
	return (0);
}
