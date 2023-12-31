/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:28:35 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:28:36 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int				id;

	id = 0;
	while ((s1[id] != '\0') && (s2[id] != '\0') && s1[id] == s2[id])
		id++;
	return ((unsigned char)s1[id] - (unsigned char)s2[id]);
}
