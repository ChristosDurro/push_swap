/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:01:54 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/13 18:39:54 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	get_node_pos(t_stack stack, int target)
{
	int	i;

	i = stack.size - 1;
	while (stack.stack)
	{
		if (stack.stack->data == target)
			return (i);
		i--;
		stack.stack = stack.stack->next;
	}
	return (0);
}

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

void	append_node(t_stack *stack, int number, int position)
{
	t_stack_node	*node;
	int				i;

	i = 0;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->data = number;
	node->pos = position;
	node->previous = NULL;
	node->next = NULL;
	if (stack->size == 0)
		stack->stack = node;
	else
	{
		node->next = stack->stack;
		stack->stack->previous = node;
		stack->stack = node;
	}
	stack->size += 1;
}

void	ft_initiailise(t_stack *stack, char **av, int ac, int start)
{
	int	i;

	i = 1;
	stack->size = 0;
	ac = ac - start;
	while (i <= ac)
	{
		append_node(stack, ft_atoi(av[ac - i + start]), i - 1);
		i++;
	}
}

void	initialise_operations(t_operations *commands)
{
	commands->ra = 0;
	commands->rb = 0;
	commands->rr = 0;
	commands->rra = 0;
	commands->rrb = 0;
	commands->rrr = 0;
}
