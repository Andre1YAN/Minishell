/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:34:47 by syan              #+#    #+#             */
/*   Updated: 2023/12/12 14:45:46 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_syntax_quote_error(char *line)
{
	if (!is_valid_quoting(&line))
	{
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		ft_putstr_fd("ERROR: Invalid quote syntax\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}

void	check_arguments(int argc)
{
	if (argc > 1)
	{
		ft_putstr_fd("Minishell:", STDERR_FILENO);
		ft_putstr_fd("ERROR: Argument list too long\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
