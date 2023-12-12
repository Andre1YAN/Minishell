/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:28:16 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:28:17 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stop_chr(char *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			dest = ft_calloc(i + 2, sizeof(char));
			dest = ft_memcpy(dest, str, i + 1);
			return (dest);
		}
		i++;
	}
	return (str);
}
