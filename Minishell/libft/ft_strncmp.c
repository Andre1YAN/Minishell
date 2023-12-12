/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:29:09 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:29:09 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1uc;
	unsigned char	*str2uc;

	str1uc = (unsigned char *) str1;
	str2uc = (unsigned char *) str2;
	i = 0;
	while (i < n && (str1uc[i] || str2uc[i]))
	{
		if (str1uc[i] != str2uc[i])
			return (str1uc[i] - str2uc[i]);
		i++;
	}
	return (0);
}
