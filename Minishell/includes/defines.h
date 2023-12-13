/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:45:00 by syan              #+#    #+#             */
/*   Updated: 2023/12/13 11:18:03 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define ARROW "> "
# define PROMPT "MiniSHELL$ "
# define INDEX_ZERO 0

# define REPLACE_VALUE 3
# define SPACE ' '
# define MARKER '\x06'

# include "../libft/libft.h"

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_tokens
{
	char	*token;
	int		id_token;
	int		index;
	t_bool	err;
}	t_tokens;

typedef struct s_minishell
{
	int			sig;
	int			*tab_id;
	int			len_tokens;
	int			fd_heredoc;
	int			exit_status;
	char		**tab_tokens;
	char		*prompt_line;
	t_list		*tks;
	t_list		*env;
	t_list		*free_me;
	t_list		*commands;
}	t_minishell;

extern t_minishell	g_ms;

enum e_tokens
{
	COMMAND = 1,
	DQUOTES = 34,
	DOLLAR_SIGN = 36,
	SQUOTE = 39,
	SLASH = 47,
	SEMICOLON = 59,
	RDRCT_IN = 60,
	RDRCT_OU = 62,
	QUERY = 63,
	PIPE = 124,
	APPEND = 2,
	HEREDOC = 3,
	DELIMITER = 4,
	FILE_APPEND = 5,
	FILE_OUT = 600,
	FILE_IN = 601,
};

#endif