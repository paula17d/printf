/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:15:39 by pdrettas          #+#    #+#             */
/*   Updated: 2024/11/12 17:23:48 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	print_percentage(void)
{
	int		bytes;
	char	percentage;

	percentage = '%';
	bytes = write(1, &percentage, 1);
	if (bytes == -1)
		bytes = -1;
	return (bytes);
}

int	print_pointer(va_list args)
{
	int				bytes;
	void			*pointer;
	unsigned long	address;
	int				sum_bytes;

	sum_bytes = 0;
	pointer = va_arg(args, void *);
	address = (unsigned long)pointer;
	bytes = write(1, "0x", 2);
	if (bytes == -1)
		return (-1);
	sum_bytes += bytes;
	if (pointer == NULL)
	{
		bytes = write(1, "0", 1);
		sum_bytes += bytes;
	}
	else
	{
		bytes = convert_hexa_lowercase(address, 0);
		sum_bytes += bytes;
	}
	if (bytes == -1)
		return (-1);
	return (sum_bytes);
}

int	print_parameter(const char *string_output, va_list args, int i)
{
	int	bytes;

	if (string_output[i] == '%' && string_output[i + 1] == 'c')
		bytes = print_char(args);
	if (string_output[i] == '%' && string_output[i + 1] == 's')
		bytes = print_str(args);
	if (string_output[i] == '%' && string_output[i + 1] == 'i')
		bytes = print_integer(args);
	if (string_output[i] == '%' && string_output[i + 1] == 'd')
		bytes = print_decimal(args);
	if (string_output[i] == '%' && string_output[i + 1] == 'u')
		bytes = print_unsigned(args);
	if (string_output[i] == '%' && string_output[i + 1] == '%')
		bytes = print_percentage();
	if (string_output[i] == '%' && string_output[i + 1] == 'p')
		bytes = print_pointer(args);
	if (string_output[i] == '%' && string_output[i + 1] == 'x')
		bytes = print_x_lowercase(args);
	if (string_output[i] == '%' && string_output[i + 1] == 'X')
		bytes = print_x_uppercase(args);
	return (bytes);
}
