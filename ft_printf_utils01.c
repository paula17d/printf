/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:13:44 by pdrettas          #+#    #+#             */
/*   Updated: 2024/11/12 17:14:27 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	print_char(va_list args)
{
	char	character;
	int		bytes;

	character = va_arg(args, int);
	bytes = write(1, &character, 1);
	if (bytes == -1)
		return (-1);
	return (bytes);
}

int	print_str(va_list args)
{
	char	*str;
	int		str_len;
	int		bytes;

	str = va_arg(args, char *);
	if (str != NULL)
	{
		str_len = ft_strlen(str);
		bytes = write(1, str, str_len);
		if (bytes == -1)
			bytes = -1;
	}
	else
	{
		bytes = write(1, "(null)", 6);
		if (bytes == -1)
			bytes = -1;
	}
	return (bytes);
}

int	print_integer(va_list args)
{
	int		integer;
	int		bytes;
	char	*str;
	int		str_len;

	integer = va_arg(args, int);
	str = ft_itoa(integer);
	if (str)
	{
		str_len = ft_strlen(str);
		bytes = write(1, str, str_len);
		free(str);
		if (bytes == -1)
			return (-1);
		return (bytes);
	}
	else
		return (-1);
}

int	print_decimal(va_list args)
{
	int		decimal;
	int		bytes;
	char	*str;
	int		str_len;

	decimal = va_arg(args, int);
	str = ft_itoa(decimal);
	if (str)
	{
		str_len = ft_strlen(str);
		bytes = write(1, str, str_len);
		free(str);
		if (bytes == -1)
			return (-1);
		return (bytes);
	}
	return (-1);
}

int	print_unsigned(va_list args)
{
	unsigned int	unsigned_integer;
	char			*str;
	int				str_len;
	int				bytes;

	unsigned_integer = va_arg(args, unsigned int);
	str = ft_uitoa(unsigned_integer);
	if (str)
	{
		str_len = ft_strlen(str);
		bytes = write(1, str, str_len);
		if (bytes == -1)
			bytes = -1;
		free(str);
		return (bytes);
	}
	return (-1);
}
