/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:15:36 by pdrettas          #+#    #+#             */
/*   Updated: 2024/11/10 19:01:43 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

#include <unistd.h>



int	print_char(va_list args)
{
	char	character;
	int		bytes;

	character = va_arg(args, char);
	bytes = write(1, &character, 1);

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
		bytes = write (1, str, str_len);
	}
	else
	{
		bytes = write (1, "(null)", 7);
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
	str_len = ft_strlen(str);
	bytes = write (1, str, str_len);

	return (bytes);
}

int	print_decimal(va_list args)
{
	int		decimal;
	int		bytes;
	char	*str;
	int		str_len;

	decimal = va_arg(args, int);
	str = ft_itoa(decimal);
	str_len = ft_strlen(str);
	bytes = write (1, str, str_len);

	return (bytes);
}

int	print_unsigned(va_list args)
{
	unsigned int	unsigned_integer;
	char			*str;
	int				str_len;
	int				bytes;

	unsigned_integer = va_arg(args, unsigned int);
	str = ft_uitoa(unsigned_integer);
	str_len = ft_strlen(str);
	bytes = write (1, str, str_len);

	return (bytes);
}

int	print_percentage(va_list args)
{
	int		bytes;
	char	percentage;

	percentage = '%';

	bytes = write (1, &percentage, 1);
	return (bytes);
}

int	print_pointer(va_list args)
{
	int		bytes;
	void	*pointer;
	unsigned long	address;

	pointer = va_arg(args, void *);
	// bytes = write (1, pointer, 1);
	address = (unsigned long)pointer;
	printf("pointer before casting = %p\n", pointer);
	printf("pointer long = %lu\n");
	return (bytes);
}

int	ft_printf(const char *string_output, ...)
{
	int		i;
	int		bytes;
	int 	len_string;
	va_list	args;

	va_start(args, string_output);

	bytes = 0;
	len_string = 0;
	i = 0;
	while ((string_output != NULL) && (string_output[i] != '\0'))
	{
		if (string_output[i] == '%' && string_output[i + 1] == 'c')
		{
			i += 2;
			bytes = print_char(args);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == 's')
		{
			i += 2;
			bytes = print_str(args);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == 'i')
		{
			i += 2;
			bytes = print_integer(args);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == 'd')
		{
			i += 2;
			bytes = print_decimal(args);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == 'u')
		{
			i += 2;
			bytes = print_unsigned(args);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == '%')
		{
			i += 2;
			bytes = print_percentage(args);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == 'p')
		{
			i += 2;
			bytes = print_pointer(args);
			len_string = len_string + bytes;
			continue;
		}

		bytes = write(1, &string_output[i], 1);
		len_string = len_string + bytes;
		i++;
	}
	return (len_string);
}

int	main()
{
	char c = 'p';
	char *str = "Paula";
	int	i = 2147483647;
	int d = -2147483648;
	unsigned int u = 4294967295;
	void	*pointer;
	pointer = &c;
	int len;
	int len2;
	
	len = ft_printf("The argument c = %c and the string = %s and the integer = %i and the decimal = %d and the unsigned = %u and percentage = %% and pointer = %p\n", c, str, i, d, u, pointer);
	printf("printed bytes = %d\n", len);
	

	// int i = -3;
	
	// printf("rgument i = %i", i);
}
// int	main()
// {
// 	int i = 3; 
// 	printf("the number = %d , hello%%\n", i); //hello%	
// }
