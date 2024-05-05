/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:39:59 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/04 15:39:59 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9
				&& str[i] <= 13)))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	*cadena;
	int			result1;
	int			result2;

	cadena = "-1234a5";
	result1 = atoi(cadena);
	result2 = ft_atoi(cadena);
	printf("result1: %d\n", result1); // Salida: 12345
	printf("result2: %d\n", result2);
	return (0);
}
*/
