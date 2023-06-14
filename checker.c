/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:54:54 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/13 16:14:21 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"
#include<string.h>

void	execute_checker(char *commands, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(commands, "ra", 3) == 0)
		ra(stack_a, 1);
	else if (ft_strncmp(commands, "rb", 3) == 0)
		rb(stack_b, 1);
	else if (ft_strncmp(commands, "rra", 4) == 0)
		rra(stack_a, 1);
	else if (ft_strncmp(commands, "rrb", 4) == 0)
		rrb(stack_b, 1);
	else if (ft_strncmp(commands, "rr", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(commands, "rrr", 4) == 0)
		rrr(stack_a, stack_b);
	else if (ft_strncmp(commands, "pa", 3) == 0)
		pa(stack_b, stack_a);
	else if (ft_strncmp(commands, "pb", 3) == 0)
		pb(stack_a, stack_b);
}

void	checker(t_stack *stack_a, t_stack *stack_b)
{
	char c[4];
	int i;
	

	i = 0;
	while (read(0, &c[i], 1))
	{
		if (c[i] != '\n')
			i++;
		else {
			c[i] = '\0';
			execute_checker(c, stack_a, stack_b);
			i = 0;
		}
	}
	
}

int main(int argc, char **argv)
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
	if (check_params(argc - 1, argv, start))
	{
		ft_printf("Error!\n");
		return (0);
	}
	ft_initiailise(&a, argv, argc, start);
	ft_initiailise(&b, argv, 0, start);
	checker(&a, &b);
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}