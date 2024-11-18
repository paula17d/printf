/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:56:23 by pdrettas          #+#    #+#             */
/*   Updated: 2024/10/28 01:13:42 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_memory;
	int		*ptr;

	total_memory = count * size;
	ptr = malloc(total_memory);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total_memory);
	return (ptr);
}
