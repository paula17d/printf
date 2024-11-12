/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:11:51 by pdrettas          #+#    #+#             */
/*   Updated: 2024/11/12 17:12:57 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	convert_hexa_uppercase(unsigned long num, int summe_bytes)
{
	int		bytes;
	int		rest;

	if (num == 0)
	{
		return (summe_bytes);
	}
	rest = num % 16;
	num = num / 16;
	summe_bytes = convert_hexa_uppercase(num, summe_bytes);
	if (summe_bytes == -1)
	{
		return (-1);
	}
	bytes = write(1, &"0123456789ABCDEF"[rest], 1);
	if (bytes == -1)
	{
		return (-1);
	}
	return (summe_bytes + bytes);
}

int	convert_hexa_lowercase(unsigned long num, int summe_bytes)
{
	int		bytes;
	int		rest;

	if (num == 0)
	{
		return (summe_bytes);
	}
	rest = num % 16;
	num = num / 16;
	summe_bytes = convert_hexa_lowercase(num, summe_bytes);
	if (summe_bytes == -1)
	{
		return (-1);
	}
	bytes = write(1, &"0123456789abcdef"[rest], 1);
	if (bytes == -1)
	{
		return (-1);
	}
	return (summe_bytes + bytes);
}

int	print_x_lowercase(va_list args)
{
	int				bytes;
	unsigned int	convert;

	convert = va_arg(args, unsigned int);
	if (convert == 0)
	{
		bytes = write(1, "0", 1);
		if (bytes == -1)
			return (-1);
	}
	else
	{
		bytes = convert_hexa_lowercase(convert, 0);
		if (bytes == -1)
			return (-1);
	}
	return (bytes);
}

int	print_x_uppercase(va_list args)
{
	int				bytes;
	unsigned int	convert;

	convert = va_arg(args, unsigned int);
	if (convert == 0)
	{
		bytes = write(1, "0", 1);
		if (bytes == -1)
			return (-1);
	}
	else
	{
		bytes = convert_hexa_uppercase(convert, 0);
		if (bytes == -1)
			return (-1);
	}
	return (bytes);
}
