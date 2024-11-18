/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:31:14 by pdrettas          #+#    #+#             */
/*   Updated: 2024/10/28 01:54:49 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	amount_of_digits(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

void	string_conversion(int n, char *str, int len)
{
	int	i;

	i = len - 1;
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		str[0] = '0';
	}
	else
	{
		while (n != 0)
		{
			str[i--] = '0' + (n % 10);
			n /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = amount_of_digits(n);
	result = (char *)malloc(len +1);
	if (!result)
		return (NULL);
	string_conversion(n, result, len);
	return (result);
}
