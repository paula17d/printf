/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:15:36 by pdrettas          #+#    #+#             */
/*   Updated: 2024/11/12 17:51:37 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *string_output, ...)
{
	int			i;
	int			bytes;
	int			sum_bytes;
	va_list		args;

	va_start(args, string_output);
	bytes = 0;
	sum_bytes = 0;
	i = 0;
	while ((string_output != NULL) && (string_output[i] != '\0'))
	{
		if (string_output[i] == '%' && string_output[i + 1] != '\0')
		{
			bytes = print_parameter(string_output, args, i);
			i += 2;
		}
		else
			bytes = write(1, &string_output[i++], 1);
		if (bytes == -1)
			return (-1);
		sum_bytes = sum_bytes + bytes;
	}
	va_end(args);
	return (sum_bytes);
}
