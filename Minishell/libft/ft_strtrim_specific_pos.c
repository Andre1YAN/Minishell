/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_specific_pos.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:29:31 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:29:32 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_specific_pos(char *str, int *pos, int term)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	k = ft_strlen(str) - ft_intarray_len(pos, term);
	dest = ft_calloc(k + 1, sizeof(char));
	i = 0;
	j = 0;
	k = 0;
	while (i < (int)ft_strlen(str))
	{
		while (i == pos[k])
		{
			i++;
			k++;
		}
		dest[j] = str[i];
		j++;
		i++;
	}
	return (dest);
}
