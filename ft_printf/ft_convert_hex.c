/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:12:07 by aestrell          #+#    #+#             */
/*   Updated: 2024/03/17 14:12:07 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_result_hex(char *result_hex)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = (int)ft_strlen(result_hex) - 1;
	while (i < j)
	{
		temp = result_hex[i];
		result_hex[i] = result_hex[j];
		result_hex[j] = temp;
		i++;
		j--;
	}
}

static char	*ft_verify_format(char flag)
{
	char	*hex_format;

	hex_format = "0123456789abcdef";
	if (flag == 'X')
		hex_format = "0123456789ABCDEF";
	return (hex_format);
}

char	*ft_convert_to_hex(unsigned long long number, char flag)
{
	char	*hex;
	char	*result_hex;
	int		i;

	hex = ft_verify_format(flag);
	result_hex = (char *)malloc(sizeof(char) * 17);
	if (result_hex == NULL)
		return (NULL);
	i = 0;
	if (number == 0)
		result_hex[i] = '0';
	else
	{
		while (number != 0 && i < 16)
		{
			result_hex[i] = hex[number % 16];
			number = number / 16;
			i++;
		}
	}
	result_hex[i] = '\0';
	ft_result_hex(result_hex);
	return (result_hex);
}
