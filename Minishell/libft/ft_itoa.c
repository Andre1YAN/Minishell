/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:26:27 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:26:27 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_int(int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (2);
	else if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				negative;
	unsigned int	size;

	negative = n < 0;
	size = ft_count_int(n);
	result = malloc(sizeof(char) * (size));
	if (result == NULL)
		return (NULL);
	result[--size] = '\0';
	if (!n)
		result[--size] = '0';
	while (n)
	{
		size--;
		result[size] = ((-negative + !negative) * (n % 10) + 48);
		n /= 10;
	}
	if (negative)
		result[--size] = '-';
	return (result);
}
