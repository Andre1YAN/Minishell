/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:26:31 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:26:31 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	t_list	*node;

	if (*lst == NULL)
		*lst = new_list;
	else
	{
		node = *lst;
		while (node->next != NULL)
			node = node->next;
		node->next = new_list;
	}
}
