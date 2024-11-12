/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:19:54 by pdrettas          #+#    #+#             */
/*   Updated: 2024/11/12 18:31:15 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		ft_printf(const char *string_output, ...);
int		print_parameter(const char *string_output, va_list args, int i);
int		convert_hexa_uppercase(unsigned long num, int summe_bytes);
int		convert_hexa_lowercase(unsigned long num, int summe_bytes);
int		print_x_lowercase(va_list args);
int		print_x_uppercase(va_list args);
int		print_char(va_list args);
int		print_str(va_list args);
int		print_integer(va_list args);
int		print_decimal(va_list args);
int		print_unsigned(va_list args);
int		print_pointer(va_list args);
int		print_percentage(void);

#endif