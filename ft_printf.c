/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:15:36 by pdrettas          #+#    #+#             */
/*   Updated: 2024/11/11 17:42:21 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

#include <unistd.h>

#include <unistd.h>

int convert_hexa_uppercase(unsigned long num, int summe_bytes) {
    int bytes;
    int rest;
    char str[17] = "0123456789ABCDEF";

    if (num == 0) {
        return summe_bytes;
    }

    rest = num % 16;
    num = num / 16;

    summe_bytes = convert_hexa_uppercase(num, summe_bytes);
    if (summe_bytes == -1) {
        return -1;
    }

    bytes = write(1, &str[rest], 1);
    if (bytes == -1) {
        return -1;  
    }

    return summe_bytes + bytes; 
}

// int	convert_hexa_uppercase(unsigned long num, int summe_bytes)
// {
// 	int bytes;
//     int rest; 
//     char str[17] = "0123456789ABCDEF";

//     if (num == 0) {
//         // if (summe_bytes == 0) {
//         //     bytes = write(1, "0", 1);
//         //     return bytes;
//         // }
//         return summe_bytes;
//     }

//     rest = num % 16;
//     num = num / 16;

//    
//     summe_bytes = convert_hexa_uppercase(num, summe_bytes);

//     
//     bytes = write(1, &str[rest], 1);
// if (bytes == -1)
// 		return -1;

// 	if (summe_bytes == -1)
// 		return -1;
//     return summe_bytes + bytes; 
// }
// int	convert_hexa_lowercase(unsigned long num, int summe_bytes)
// {
// 	int bytes;
// 	int rest; 

// 	if (num == 0)
// 		return (0);

// 	rest = num % 16;
// 	num = num / 16;
// 	convert_hexa_lowercase(num, summe_bytes);
// 	char str[18] = "0123456789abcdef\0";
// 	bytes = write(1, &str[rest], 1);
// 	summe_bytes = summe_bytes + bytes;
// 	return (summe_bytes);
// }

int convert_hexa_lowercase(unsigned long num, int summe_bytes) {
     int bytes;
    int rest;
    char str[17] = "0123456789abcdef";

    if (num == 0) {
        return summe_bytes;
    }

    rest = num % 16;
    num = num / 16;

    summe_bytes = convert_hexa_lowercase(num, summe_bytes);
    if (summe_bytes == -1) {
        return -1; 
    }

    bytes = write(1, &str[rest], 1);
    if (bytes == -1) {
        return -1;  
    }

    return summe_bytes + bytes;  
}

int	print_x_lowercase(va_list args)
{
	int				bytes;
	unsigned int	convert;

	convert = va_arg(args, unsigned int);
	if (convert == 0)
	{
		bytes = write(1,"0",1);
		if (bytes == -1)
			return -1;
	}
	else
	{
		
	bytes = convert_hexa_lowercase (convert, 0);
	if (bytes == -1)
			return -1;
	}

	return (bytes);
}

int	print_X_uppercase(va_list args)
{
	int				bytes;
	unsigned int	convert;

	convert = va_arg(args, unsigned int);
	if (convert == 0)
	{
		bytes = write(1,"0",1);
		if (bytes == -1)
			return -1;
	}
	else
	{
	bytes = convert_hexa_uppercase (convert, 0);
	if (bytes == -1)
			return -1;
	}
	return (bytes);
}

int	print_char(va_list args)
{
	char	character;
	int		bytes;

	character = va_arg(args, int);
	bytes = write(1, &character, 1);
	if (bytes == -1)
			return -1;

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
		if (bytes == -1)
			bytes = -1;
	}
	else
	{
		bytes = write (1, "(null)", 6);
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
	if(str)
	{
	str_len = ft_strlen(str);
	bytes = write (1, str, str_len);
	
	free(str);
	if (bytes == -1)
			return -1;
		
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
	if(str)
	{
	str_len = ft_strlen(str);
	bytes = write (1, str, str_len);
	free(str);
	if (bytes == -1)
			return -1;

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
	bytes = write (1, str, str_len);
	if (bytes == -1)
			bytes = -1;
	free(str);
	return (bytes);
		
	}
	return (-1);

}

int	print_percentage(void)
{
	int		bytes;
	char	percentage;

	percentage = '%';

	bytes = write (1, &percentage, 1);
	if (bytes == -1)
			bytes = -1;
	return (bytes);
}

int	print_pointer(va_list args)
{
	int		bytes;
	void	*pointer;
	unsigned long	address;
	int summe_bytes = 0;

	pointer = va_arg(args, void *);
	// bytes = write (1, pointer, 1);
	address = (unsigned long)pointer;
	bytes = write (1, "0x", 2);//2
	if (bytes == -1)
			return (-1);
		summe_bytes += bytes; 
	if (pointer == NULL)
	{
		bytes = write (1, "0", 1);//2
		if (bytes == -1)
			return (-1);
		summe_bytes += bytes; 
	}
	else{
		
	bytes = convert_hexa_lowercase (address, 0);//11
	if (bytes == -1)
			return (-1);
		summe_bytes += bytes; 
	}
	// printf("pointer before casting = %p\n", pointer);
	// printf("pointer long = %lu\n");
	return (summe_bytes);
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
			if (bytes == -1)
			return (-1);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == 's')
		{
			i += 2;
			bytes = print_str(args);
			if (bytes == -1)
			return (-1);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == 'i')
		{
			i += 2;
			bytes = print_integer(args);
			if (bytes == -1)
			return (-1);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == 'd')
		{
			i += 2;
			bytes = print_decimal(args);
			if (bytes == -1)
			return (-1);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == 'u')
		{
			i += 2;
			bytes = print_unsigned(args);
			if (bytes == -1)
			return (-1);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == '%')
		{
			i += 2;
			bytes = print_percentage();
			if (bytes == -1)
			return (-1);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == 'p')
		{
			i += 2;
			bytes = print_pointer(args);
			if (bytes == -1)
			return (-1);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == 'x')
		{	
			i += 2;
			bytes = print_x_lowercase(args);
			if (bytes == -1)
			return (-1);
			len_string = len_string + bytes;
			continue;
		}
		if (string_output[i] == '%' && string_output[i + 1] == 'X')
		{	
			i += 2;
			bytes = print_X_uppercase(args);
			if (bytes == -1)
			return (-1);
			len_string = len_string + bytes;
			continue;
		}

		bytes = write(1, &string_output[i], 1);
		if (bytes == -1)
			return (-1);
		len_string = len_string + bytes;
		i++;
	}
	return (len_string);
}

