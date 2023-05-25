/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:01:54 by cdurro            #+#    #+#             */
/*   Updated: 2023/05/25 15:24:31 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	get_node_pos(t_stack_node *stack, t_stack_node *target)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack == target)
			return (i);
		i++;
	}
	return(0);
}

t_stack_node *find_last_node(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_stack_node **stack, int number, int position)
{
	t_stack_node *node;
	t_stack_node *last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->data = number;
	node->pos = position;
	if (!(*stack))
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->previous = node;
		node->next = last_node;
	}
}

void	ft_initiailise(t_stack_node **stack, char **av, int ac)
{
	int i;
	int len;

	i = 1;
	while (i < ac)
	{
		append_node(stack, ft_atoi(av[i]), i);
		i++;
	}
	// i = 0;
	// len = stack_len(*stack);
	// while (stack)
	// {
	// 	if ((*stack)->pos > len / 2)
	// 		(*stack)->above_mid = 1;
	// 	else
	// 		(*stack)->above_mid = 0;
	// 	*stack = (*stack)->next;
	// }
}
