/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:26:47 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:26:48 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcount_nodes(t_list *lst)
{
	int		count;
	t_list	*env_node;

	count = 0;
	env_node = lst;
	if (!env_node)
		return (count);
	while (env_node != NULL)
	{
		count++;
		env_node = env_node->next;
	}
	return (count);
}
