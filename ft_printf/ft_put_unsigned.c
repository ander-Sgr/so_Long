/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:42:06 by aestrell          #+#    #+#             */
/*   Updated: 2024/03/10 17:42:06 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_convert_to_arr(unsigned int nbr, int size)
{
	int		i;
	char	*arr_int;

	if (nbr == 0)
	{
		arr_int = (char *)malloc(2 * sizeof(char));
		if (arr_int == NULL)
			return (NULL);
		arr_int[0] = '0';
		arr_int[1] = '\0';
		return (arr_int);
	}
	i = size - 1;
	arr_int = (char *)malloc((size + 1) * sizeof(char));
	if (arr_int == NULL)
		return (NULL);
	while (nbr != 0 && i >= 0)
	{
		arr_int[i] = '0' + (nbr % 10);
		nbr = nbr / 10;
		i--;
	}
	arr_int[size] = '\0';
	return (arr_int);
}

static char	*ft_utoa(unsigned int n)
{
	unsigned int	total_digits;
	char			*arr_int;

	total_digits = ft_count_digits(n);
	arr_int = ft_convert_to_arr(n, total_digits);
	return (arr_int);
}

int	ft_put_unsigned(unsigned int nbr)
{
	char	*str;
	int		len;

	str = ft_utoa(nbr);
	len = (int)ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
