/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syan <syan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:28:12 by syan              #+#    #+#             */
/*   Updated: 2023/12/11 14:28:12 by syan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_count(char const *s, char c)
{
	int		i;
	char	*a;

	i = 0;
	a = (char *) s;
	while (*a)
	{
		while (*a == c)
			a++;
		if (!(*a))
			break ;
		while (*a != c && *a != 0)
			a++;
		i++;
	}
	return (i);
}

static int	word_len(char const *s, char c)
{
	unsigned int	i;
	char			*a;

	i = 0;
	a = (char *) s;
	while (*a == c)
		a++;
	while (a[i] && a[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*aux;
	int		wc;
	int		j;

	j = 0;
	wc = split_count((char *) s, c);
	tab = malloc(sizeof(char **) * (wc + 1));
	if (!tab)
		return (NULL);
	while (split_count(&s[j], c))
	{
		while (s[j] == c)
			j++;
		aux = malloc(sizeof(char) * (word_len(&s[j], c) + 1));
		if (!aux)
			return (NULL);
		ft_strlcpy(aux, &s[j], word_len(&s[j], c) + 1);
		tab[wc - split_count(&s[j], c)] = aux;
		j += word_len(&s[j], c);
	}
	tab[wc] = NULL;
	return (tab);
}
