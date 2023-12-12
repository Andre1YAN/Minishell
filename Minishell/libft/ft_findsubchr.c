/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findsubchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:03:57 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:24:24 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_findsubchr(char *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			dest = ft_calloc(i + 1, sizeof(char));
			dest = ft_memcpy(dest, str, i);
			return (dest);
		}
		i++;
	}
	return (ft_strdup(str));
}
