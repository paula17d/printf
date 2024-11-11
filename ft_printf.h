/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:19:54 by pdrettas          #+#    #+#             */
/*   Updated: 2024/11/11 16:27:33 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_uitoa(unsigned int n);
int		ft_printf(const char *string_output, ...);
char	*ft_strdup(const char *s1);

#endif