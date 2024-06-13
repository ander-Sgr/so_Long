/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:12:30 by aestrell          #+#    #+#             */
/*   Updated: 2024/03/17 14:12:30 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_convert_hex(unsigned int value, char flag)
{
	return (ft_convert_to_hex(value, flag));
}

int	ft_put_hexadecimal(unsigned int ptr, char flag)
{
	int		len_result;
	char	*result_hex;

	len_result = 0;
	if (ptr == 0)
		len_result += write(1, "0", 1);
	else
	{
		result_hex = ft_convert_hex(ptr, flag);
		if (result_hex != NULL)
		{
			len_result += ft_put_string(result_hex);
			free(result_hex);
		}
	}
	return (len_result);
}
