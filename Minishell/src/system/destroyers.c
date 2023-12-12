/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:28:19 by syan              #+#    #+#             */
/*   Updated: 2023/12/12 14:22:40 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	destroy_minishell(void)
{
	ft_lstclear(&g_ms, destroy_t_tokens);
	free(g_ms.prompt_line);
	free(g_ms.tab_tokens);
	free(g_ms.tab_id);
}

void	destroy_t_tokens(void *token)
{
	t_tokens	*tklist;

	tklist = (t_tokens *)token;
	free(tklist->token);
	free(tklist);
}