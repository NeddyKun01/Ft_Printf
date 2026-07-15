/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddykun <neddykun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:23:28 by neddykun          #+#    #+#             */
/*   Updated: 2026/07/05 21:25:08 by neddykun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** PT: Salta os separadores ate encontrar texto.
** EN: Skips delimiters until real text appears.
*/
static size_t	skip_delims(const char *s, char c, size_t i)
{
	while (s[i] == c)
		i++;
	return (i);
}

/*
** PT: Conta quantas palavras existem na string.
** EN: Counts how many words are in the string.
*/
static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		i = skip_delims(s, c, i);
		if (!s[i])
			break ;
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

/*
** PT: Liberta o que ja foi criado e depois a lista de palavras.
** EN: Frees what was created and then frees the word array.
*/
static char	**free_split(char **split, size_t used)
{
	while (used > 0)
		free(split[--used]);
	free(split);
	return (NULL);
}

/*
** PT: Tira cada palavra uma a uma e guarda-a no resultado.
** EN: Extracts each word one by one and stores it in the result.
*/
static char	**fill_split(char **split, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		i = skip_delims(s, c, i);
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		split[j] = ft_substr(s, start, i - start);
		if (!split[j])
			return (free_split(split, j));
		j++;
	}
	split[j] = NULL;
	return (split);
}

/*
** PT: Parte uma string numa lista terminada por NULL.
** EN: Splits a string into a NULL-terminated list.
*/
char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	return (fill_split(split, s, c));
}
