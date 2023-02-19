/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:22:44 by oburato           #+#    #+#             */
/*   Updated: 2022/05/10 10:29:13 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words_counter(char const *s, char sep)
{
	size_t	words_count;

	words_count = 0;
	if (!*s)
		return (words_count);
	if (!ft_strchr(s, sep))
		return (1);
	while (*s)
	{
		while (*s && *s == sep)
			s++;
		if (*s && *s != sep)
		{
			while (*s && *s != sep)
				s++;
			words_count++;
		}
	}
	return (words_count);
}

static char	*ft_copy(char *dst, char *start, size_t *len)
{
	size_t	index;

	index = 0;
	while (index < *len)
	{
		*dst = start[index];
		index++;
		dst++;
	}
	*dst = '\0';
	*len = 0;
	return (dst);
}

static char	**ft_fill_words(char **split, const char *s,
char c, size_t split_index)
{
	char	*start_word;
	size_t	word_len;

	word_len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			start_word = (char *)s;
			while (*s && *s != c)
			{
				word_len++;
				s++;
			}
			split[split_index] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (!split[split_index])
				return (NULL);
			ft_copy(split[split_index++], start_word, &word_len);
		}
	}
	split[split_index] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	split_index;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_words_counter(s, c) + 1));
	if (!split)
		return (NULL);
	split_index = 0;
	split = ft_fill_words(split, s, c, split_index);
	if (!split)
		return (NULL);
	return (split);
}
