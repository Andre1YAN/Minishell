/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_allchars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:29:26 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:29:27 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_allchars(char *str, char c)
{
	char	*dest;
	int		count;
	int		i;
	int		j;

	if (ft_strchr(str, c) == NULL)
		return (ft_strdup(str));
	count = ft_strchr_count(str, c);
	dest = ft_calloc(ft_strlen(str) - (count - 1), sizeof(char));
	i = 0;
	j = 0;
	while (i < (int) ft_strlen(str))
	{
		while (str[i] == c)
			i++;
		dest[j] = str[i];
		j++;
		i++;
	}
	return (dest);
}
