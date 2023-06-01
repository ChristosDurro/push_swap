/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:19:43 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/01 13:59:07 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include"push_swap.h"
#include"libft/libft.h"
#include"ft_printf/ft_printf.h"


void	print_stack(t_stack stack, int bool)
{
	printf("\n");
	while (stack.size--)
	{
		printf(" %i\t-> index", stack.stack->data);
		printf(" %i\n", stack.stack->pos);
		stack.stack = stack.stack->next;
	}
	ft_printf("---\n");
	if (bool)
		ft_printf(" a\n");
	else
		ft_printf(" b\n");
	printf("\n");

}

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	int		i;

	if (argc == 1 || !argv[1][0])
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = count_args(argv);
	}
	if (check_params(argc - 1, argv))
	{
		ft_printf("Error!\n");
		return (0);
	}
	ft_initiailise(&a, argv, argc - 1);
	ft_initiailise(&b, argv, 0);

	print_stack(a, 1);
	// printf("biggest pos: %i\n", get_node_pos(a, highest_node(a)));
	// r_rotate(a);
	// printf("biggest pos after rotate: %i\n", get_node_pos(a, highest_node(a)));
	// tiny_sort(&a);
	// five_sort(&a, &b);
	big_sort(&a, &b);
	// print_stack(a, 1);
	// print_stack(b, 0);
	// my_sort(&a, &b);
	//print_stack(&b, 0);
	// while (a)
	// {
	// 	printf(" %i\n", a->data);
	// 	a = a->next;


	// }

	return (0);
}
