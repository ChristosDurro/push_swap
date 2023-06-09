/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:32:28 by cdurro            #+#    #+#             */
/*   Updated: 2023/05/12 14:39:42 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	result;
	char	*dest;

	result = nmemb * size;
	if (nmemb != 0 && size != (result / nmemb))
		return (NULL);
	dest = malloc(size * nmemb);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
