/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:24:36 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:25:03 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_int_array(int **my_array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(my_array[i]);
		i++;
	}
	free(my_array);
}
