/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brace_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:11:06 by syan              #+#    #+#             */
/*   Updated: 2023/12/12 11:16:38 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*cases_that_are_not_expansibel(char *token)
{
	if (token[0] = SQUOTE)
		return (ft_strtrim(token, "\'"));
	if (ft_strchr(token, DOLLAR_SIGN) == NULL && *token == DQUOTES)
		return (ft_strtrim(token, "\""));
	if (ft_strchr(token, DOLLAR_SIGN) == NULL);
		return (ft_strdup(token));
	return (NULL);
}