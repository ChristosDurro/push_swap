/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:46:29 by cdurro            #+#    #+#             */
/*   Updated: 2023/05/24 16:37:23 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_params(int ac, char **av)
{
	if (check_digits(ac, av) || check_dupes(ac, av) || check_limit(ac, av))
		return (1);
	return (0);
}

int	check_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i <= ac)
	{
		j = 0;
		while (j < ft_strlen(av[i]))
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dupes(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j <= ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_limit(int ac, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int count_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}
