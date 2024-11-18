/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:08:09 by pdrettas          #+#    #+#             */
/*   Updated: 2024/10/28 01:55:37 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *goal, const char *start)
{
	char	*temp;

	temp = goal;
	while (*start != '\0')
		*temp++ = *start++;
	*temp = '\0';
	return (goal);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*result;

	s1_len = 0;
	s2_len = 0;
	if (s1 == (NULL) && s2 == (NULL))
		return (NULL);
	if (s1 != (NULL))
		s1_len = ft_strlen(s1);
	if (s2 != (NULL))
		s2_len = ft_strlen(s2);
	total_len = (s1_len + s2_len) + 1;
	result = malloc(total_len * sizeof(char));
	if (result == (NULL))
		return (NULL);
	if (s1 != NULL)
		ft_strcpy(result, s1);
	if (s2 != NULL)
		ft_strcpy(result + s1_len, s2);
	return (result);
}
