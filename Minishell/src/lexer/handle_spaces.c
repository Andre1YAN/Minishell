/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:30 by syan              #+#    #+#             */
/*   Updated: 2023/12/13 11:07:21 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_qtt_to_be_incremented(char *line)
{
	int	value;
	int	i;

	i = 0;
	value = 0;
	if (line[i] == SQUOTE || line[i] == DQUOTES)
	{
		value = line[i];
		i++;
		while (line[i] && line[i] != value)
			i++;
		i++;
	}
	else if (line[i] == RDRCT_IN && line[i + 1] == RDRCT_IN)
		i += 2;
	else if (line[i] == RDRCT_OU && line[i + 1] == RDRCT_OU)
		i += 2;
	else
		i++;
	return (i);
}

char	*add_spaces_specific_tokens(char *line, int count)
{
	char		*str;
	int			value;
	size_t		i;
	int			j;

	i = 0;
	j = 0;
	str = ft_calloc(1, ft_strlen(line) + count * 2 + 1);
	while (i < ft_strlen(line))
	{
		if (check_for_specific_token(line[i]) == TRUE)
		{
			str[j] = SPACE;
			j++;
			value = check_qtt_to_be_incremented(&line[i]);
			while (value--)
				str[j++] = line[i++];
			str[j] = SPACE;
			j++;
		}
		else
			str[j++] = line[i++];
	}
	return (str);
}

void	replace_value_inside_quotes(char *list, int old_vle, int new_vle)
{
	char	*str;
	int		quotes;
	int		i;

	i = 0;
	str = list;
	quotes = 0;
	while (str[i])
	{
		if (str[i] == SQUOTE || str[i] == DQUOTES)
		{
			quotes = str[i];
			i++;
			while (str[i] && str[i] != quotes)
			{
				if (str[i] == old_vle)
					str[i] = new_vle;
				i++;
			}
			i++;
		}
		while (str[i] && str[i] != SQUOTE && str[i] != DQUOTES)
			i++;
	}
}

char	*add_chrs_in_specific_position(char *line, int index, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_calloc(1, ft_strlen(line) + 2);
	while (i < (int)ft_strlen(line) + 1)
	{
		if (j == index)
			str[j++] = c;
		str[j] = line[i];
		i++;
		j++;
	}
	str[i] = '\0';
	free(line);
	return (str);
}
