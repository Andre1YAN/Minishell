/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:28:50 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:28:50 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	leng;
	char	*newstr;

	leng = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = (char *) ft_calloc(leng, sizeof(char));
	ft_strlcat(newstr, s1, leng);
	ft_strlcat(newstr, s2, leng);
	return (newstr);
}
