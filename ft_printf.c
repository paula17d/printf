/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:15:36 by pdrettas          #+#    #+#             */
/*   Updated: 2024/11/10 14:13:48 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

int print_char(va_list args)
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

	str = va_arg(args, char *);
	str_len = ft_strlen(str);
	write (1, str, str_len);

	return (str_len);
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
	ft_printf("The argument c = %c and the string = %s\n", c, str);
	// int i = 3;
	
	// printf("The argument c = %c argument str = %s argument i = %d", c, str, i);
}

// push am sonntag!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!