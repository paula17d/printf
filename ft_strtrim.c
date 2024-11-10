/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:55:27 by pdrettas          #+#    #+#             */
/*   Updated: 2024/10/28 16:50:41 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	exists_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	starting_point(const char *s, const char *set)
{
	int	start;

	start = 0;
	while (s[start] != '\0' && exists_in_set(s[start], set))
	{
		start++;
	}
	return (start);
}

static int	ending_point(const char *s, const char *set)
{
	int	end;

	end = ft_strlen(s) - 1;
	while (end >= 0 && exists_in_set(s[end], set))
	{
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		start;
	int		end;
	char	*result;
	size_t	trimmed_len;

	i = 0;
	start = 0;
	if (!s1 || !set)
		return (NULL);
	start = starting_point(s1, set);
	end = ending_point(s1, set);
	if (start > end)
		return (ft_strdup(""));
	trimmed_len = (end - start + 1);
	result = malloc(trimmed_len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, trimmed_len + 1);
	return (result);
}
