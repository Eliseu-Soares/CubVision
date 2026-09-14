/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:55:18 by sgaspar           #+#    #+#             */
/*   Updated: 2025/09/02 16:08:13 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words_split(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static size_t	get_next_word_len(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s == c)
		s++;
	while (*s && *s++ != c)
		i++;
	return (i);
}

static void	write_words(char **result, char *str, size_t word_count, char c)
{
	size_t	word_size;
	size_t	i;

	i = 0;
	while (i < word_count)
	{
		word_size = get_next_word_len(str, c);
		while (str[0] == c)
			str++;
		result[i] = ft_substr(str, 0, word_size);
		str = (str + word_size + 1);
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	*str;
	char	**result;

	str = (char *)s;
	if (*s == '\0' || s == NULL)
	{
		result = (char **)malloc(sizeof(char *) * 1);
		if (result != NULL)
			result[0] = NULL;
		return (result);
	}
	word_count = ft_count_words_split(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	write_words(result, str, word_count, c);
	result[word_count] = NULL;
	return (result);
}
