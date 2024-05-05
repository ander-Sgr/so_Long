/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:27:22 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/15 22:31:18 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_convert_to_arr(long nbr, int size)
{
	char	*arr_int;
	int		i;

	arr_int = ft_calloc(size + 1, sizeof(char));
	if (arr_int == NULL)
		return (NULL);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		arr_int[0] = '-';
	}
	if (nbr == 0)
		arr_int[0] = '0';
	i = size - 1;
	while (nbr != 0)
	{
		arr_int[i] = 48 + (nbr % 10);
		nbr = nbr / 10;
		i--;
	}
	arr_int[size] = '\0';
	return (arr_int);
}

char	*ft_itoa(int n)
{
	int		total_digits;
	char	*arr_int;
	long	nbr;

	nbr = n;
	total_digits = ft_count_digits(nbr);
	arr_int = ft_convert_to_arr(nbr, total_digits);
	return (arr_int);
}

/*
#include <stdio.h>
int main()
{
    long  num = -2147483647;
    char *result = ft_itoa(num);
    if (result != NULL)
    {
        printf("Converted number: %s\n", result);
        free(result);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
*/
