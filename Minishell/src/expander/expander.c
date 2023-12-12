/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:45:25 by syan              #+#    #+#             */
/*   Updated: 2023/12/12 15:49:10 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*empty_case(t_list *node, t_list *prev)
{
	t_list	*next;
	
	next = node->next;
	if (prev)
		prev->next = next;
	else
		g_ms.tks = next;
	destroy_t_tokens(node);
	return (next);
}

char	*minishell_expansion(char *token)
{
	char	*str;
	
	str = case_that_are_not_expansible(token);
	if (str != NULL)
		return (str);
	str = expand_variables(token);
	if (*token == DQUOTES)
		return (ft_strupdate(&str, ft_strtrim(str, "\"")), str);
	return (str);
}

void	expander(void)
{
	char			*temp;
	t_tokens		*tklist;
	t_list			*node;
	t_list			*prev;
	
	if (!g_ms.tks)
		return ;
	node = g_ms.tks;
	prev = NULL;
	while (node)
	{
		tklist = (t_tokens *)node->content;
		temp = minishell_expansion(tklist->token);
		free(tklist->token);
		if (ft_strlen(temp) == 0)
		{
			node = empty_case(node, prev);
			free(temp);
			continue ;
		}
		tklist->token = temp;
		prev = node;
		node = node->next;
	}
}
