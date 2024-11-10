/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:25:45 by pdrettas          #+#    #+#             */
/*   Updated: 2024/10/28 01:15:04 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;
	unsigned char		match;

	i = 0;
	ptr = (const unsigned char *)s;
	match = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == match)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
