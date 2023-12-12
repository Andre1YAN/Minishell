/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:27:16 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:27:16 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*struc;
	unsigned char	charuc;

	struc = (unsigned char *) str;
	charuc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (struc[i] == charuc)
			return (&struc[i]);
		i++;
	}
	return (NULL);
}
