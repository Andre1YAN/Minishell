/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:28:40 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:28:40 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*newstr;
	char	*res;
	size_t	leng;

	leng = ft_strlen(str)+1;
	newstr = (char *) ft_calloc(leng, sizeof(char));
	if (newstr == NULL)
		return (NULL);
	res = ft_memmove(newstr, str, leng);
	return (res);
}
