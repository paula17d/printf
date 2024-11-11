/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:25:46 by pdrettas          #+#    #+#             */
/*   Updated: 2024/11/11 16:43:43 by pdrettas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	char c = 'p';
	char *str = "Paula";
	int	i = 2147483647;
	int d = -2147483648;
	unsigned int u = 14;
	void	*pointer;
	pointer = NULL;
	int len;
	int len2;
	
	len = ft_printf("The argument c = %c and the string = %s and the integer = %i and the decimal = %d and the unsigned = %u and percentage = %% and hexa_lowercase = %x and hexa_uppercase = %X and pointer = %p\n", c, str, i, d, u, u, u, pointer);
	len2 =printf("The argument c = %c and the string = %s and the integer = %i and the decimal = %d and the unsigned = %u and percentage = %% and hexa_lowercase = %x and hexa_uppercase = %X and pointer = %p\n", c, str, i, d, u, u, u, pointer);

	printf("printed bytes = %d\n", len);
	printf("printed bytes = %d\n", len2);
}

// 	int nummer = -3;
	
// 	printf("rgument i = %x", nummer);

// int	main()
// {
// 	int nummer = 15;
	
// 	printf("rgument i = %x", nummer);
// }
