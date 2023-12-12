/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:49:52 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:53:21 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_minishell(char **argv, char **envp)
{
	(void)argv;
	g_ms.tab_tokens = NULL;
	g_ms.tab_id = NULL;
	g_ms.tks = NULL;
	g_ms.env = NULL;
	g_ms.len_tokens = 0;
	g_ms.exit_status = 0;
	create_env(envp);
}
