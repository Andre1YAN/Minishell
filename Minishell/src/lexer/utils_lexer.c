/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:06:24 by syan              #+#    #+#             */
/*   Updated: 2023/12/12 10:03:52 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	reverse_replace(char **table_tokens, int len_tab)
{
	int	i;

	i = -1;
	while (len_tab > ++i)
		replace_value_inside_quotes(table_tokens[i], REPLACE_VALUE, SPACE);
}

int	check_len_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != NULL)
		i++;
	g_ms.len_tokens = i;
	return (i);
}

t_bool	check_for_specific_token(char c)
{
	if (c == RDRCT_IN || \
		c == RDRCT_OU || \
		c == PIPE || \
		c == SQUOTE || \
		c == DQUOTES || \
		c == MARKER)
		return (TRUE);
	return (FALSE);
}

void	qtt_tokens_quotes(int value, char *line, int *i, int *qtt_tokens)
{
	value = line[*i];
	*i += 1;
	while (line[*i] && line[*i] != value)
		*i += 1;
	if (line[*i] == value)
		*qtt_tokens += 1;
}

int	qtt_tokens_heredoc_or_append(int *i, int *qtt_tokens)
{
	*qtt_tokens += 1;
	*i += 1;
	return(*qtt_tokens);
}