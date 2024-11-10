/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:47:58 by pdrettas          #+#    #+#             */
/*   Updated: 2024/10/28 01:55:16 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	word_counter;

	i = 0;
	word_counter = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word_counter++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
		{
			i++;
		}
	}
	return (word_counter);
}

static void	free_split(char **words, int num_words)
{
	int	temp;

	temp = 0;
	while (temp < num_words)
	{
		free(words[temp]);
		temp++;
	}
	free(words);
}

static char	*extract_word(char const *s, char c, int *word_start)
{
	int		start;
	int		end;
	char	*cur_word;

	start = *word_start;
	while (s[start] != '\0' && s[start] != c)
		start++;
	end = start;
	if (start == *word_start)
	{
		*word_start = start + 1;
		return (NULL);
	}
	cur_word = malloc((end - *word_start + 1) * sizeof(char));
	if (!cur_word)
		return (NULL);
	ft_strlcpy(cur_word, s + *word_start, (end - *word_start + 1));
	if (s[end] == '\0')
		*word_start = end;
	else
		*word_start = end + 1;
	return (cur_word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		num_words;
	char	**words;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	words = malloc((num_words + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	while (j < num_words)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		words[j] = extract_word(s, c, &i);
		if (!words[j])
			return (free_split(words, j), NULL);
		j++;
	}
	words[j] = NULL;
	return (words);
}
