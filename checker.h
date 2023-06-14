/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:56:09 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/13 15:39:49 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include"lib/libft.h"
#include"lib/ft_printf.h"
#include"push_swap.h"

void	checker(t_stack *stack_a, t_stack *stack_b);
void	execute_checker(char *commands, t_stack *stack_a, t_stack *stack_b);


#endif