/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:19:47 by syan              #+#    #+#             */
/*   Updated: 2023/12/13 14:07:21 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "defines.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>

/* -----------------------------------------------------------------------*\
									system
\* -----------------------------------------------------------------------*/

int			is_syntax_quote_error(char *line);
int			check_prompt(char *line);
int			get_size_node(t_list *node);
char		*create_prompt(void);
void		init_minishell(char **argv, char **envp);
void		check_arguments(int argc);
void		destroy_minishell(void);
void		destroy_t_tokens(void *token);
t_bool		is_valid_quoting(char **list);

/* -----------------------------------------------------------------------*\
									lexer
\* -----------------------------------------------------------------------*/

int			check_qtt_to_be_incremented(char *line);
int			count_specific_tokens(char *str);
int			check_len_tab(char **str);
int			*identify_tokens(char **str, int len_tab);
char		*add_marker(char *line);
char		*add_spaces_specific_tokens(char *arg, int count);
char		*add_chrs_in_specific_position(char *line, int index, char c);
void		create_tokens(void);
void		replace_value_inside_quotes(char *list, int old_vle, int new_vle);
void		reverse_replace(char **table_tokens, int len_tab);
void		create_token_list(char **str, int *id, int len);
void		get_quotes(int value, char line, int *i, int **qtt_tokens);
void		reidentify_some_tokens(t_list *tks);
t_bool		check_for_specific_token(char c);
t_tokens	*create_content(char *tks, int index, int id);

/* -----------------------------------------------------------------------*\
									parser
\* -----------------------------------------------------------------------*/

int			parser(void);
int			qtt_tokens_heredoc_or_append(int *i, int *qtt_tokens);
int			is_single_metachar(char *token, int id, int len_tokens);
int			consecutive_metachars(char *tk, char *next_tk, int id, int next_id);
int			error_syntaxy_metachars(t_list *tks, int len_tokens);
void		qtt_tokens_quotes(int value, char *line, int *i, int *qtt_tokens);
void		msg_error_invalid_synax(char *token);
void		handle_signal(void);
void		signal_break_heredoc(int signal);
t_bool		is_metachars(int id_tks);

/* -----------------------------------------------------------------------*\
									expander
\* -----------------------------------------------------------------------*/

int			check_last_expansion_occurrence(char *token);
char		*minishell_expansion(char *token);
char		*is_envar_expansible(char *token, int *i, char **final_str);
char		*cases_that_are_not_expansible(char *token);
void		expander(void);
void		expand_check_next_character(char *token, int *i, char **final_str);
t_bool		is_brace_expansion(char *token, int *i, char **final_str);
t_bool		is_envar_between_squote(char *token);

/* -----------------------------------------------------------------------*\
									builtins
\* -----------------------------------------------------------------------*/

void		create_env(char **envp);

#endif