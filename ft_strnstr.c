/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:58:36 by pdrettas          #+#    #+#             */
/*   Updated: 2024/10/24 21:05:04 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	point;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			point = 0;
			while (haystack[i + point] == needle[point] && \
			(i + point) < len && needle[point] != '\0')
			{
				point++;
			}
			if (needle[point] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
