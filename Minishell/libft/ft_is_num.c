/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:25:19 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:25:23 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_num(char *nbr)
{
	int	len;

	len = ft_strlen(nbr);
	if (nbr[len - 1] == '.')
		return (0);
	while (*nbr)
	{
		if (ft_isalpha(*nbr))
			return (0);
		nbr++;
	}
	if (*nbr == '+' || *nbr == '-')
		nbr++;
	if (*nbr == '.')
		return (0);
	while (ft_isdigit(*nbr))
		nbr++;
	if (!(*nbr))
		return (1);
	nbr++;
	while (ft_isdigit(*nbr))
		nbr++;
	if (*nbr)
		return (0);
	return (1);
}
