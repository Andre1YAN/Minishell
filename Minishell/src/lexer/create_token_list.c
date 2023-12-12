/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:30:43 by syan              #+#    #+#             */
/*   Updated: 2023/12/12 15:46:01 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tokens	*create_content(char *tks, int index, int key)
{
	t_tokens	*content;

	content = ft_calloc(1, sizeof(t_tokens));
	content->token = tks;
	content->id_token = index;
	content->index = key;
	return (content);
}

void	create_token_list(char **str, int *id, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		ft_lstadd_back(&g_ms.tks,
			ft_lstnew(create_content(str[i], id[i], i)));
}
