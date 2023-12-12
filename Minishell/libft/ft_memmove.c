/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:27:29 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:27:29 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ucdest;
	unsigned char	*ucsrc;
	int				i;

	i = n - 1;
	ucdest = (unsigned char *) dest;
	ucsrc = (unsigned char *) src;
	if (dest > src)
	{
		while (i >= 0)
		{
			ucdest[i] = ucsrc[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int) n)
		{
			ucdest[i] = ucsrc[i];
			i++;
		}
	}
	return (dest);
}
