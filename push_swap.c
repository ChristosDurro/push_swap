/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:19:43 by cdurro            #+#    #+#             */
/*   Updated: 2023/05/25 15:21:25 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include"push_swap.h"
#include"libft/libft.h"
#include"ft_printf/ft_printf.h"


int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
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
	ft_initiailise(&a, argv + 1, argc - 1);
	//my_sort(&a, &b);
	// ft_printf("\n");
	printf("%i", a->data);
	return (0);
}
