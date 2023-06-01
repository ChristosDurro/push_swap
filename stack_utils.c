/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:01:54 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/01 17:05:58 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


int	get_node_pos(t_stack stack, int	target)
{
	int	i;

	i = 0;
	while (stack.stack)
	{
		if (stack.stack->data == target)
			return (i);
		i++;
		stack.stack = stack.stack->next;
	}
	return(0);
}


t_stack_node *find_last_node(t_stack head)
{
	if (!head.size)
		return (NULL);
	while (head.stack->next)
		head.stack = head.stack->next;
	return (head.stack);
}

void	append_node(t_stack *stack, int number, int position)
{
	t_stack_node *node;

	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->data = number;
	node->pos = position;
	node->cost = 0;
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

void	ft_initiailise(t_stack *stack, char **av, int ac)
{
	int i;
	
	i = 1;
	stack->size = 0;
	while (i <= ac)
	{
		append_node(stack, ft_atoi(av[ac - i + 1]), i - 1);
		i++;
	}
}
