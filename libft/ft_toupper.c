/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:56:45 by aestrell          #+#    #+#             */
/*   Updated: 2024/01/22 16:56:45 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	result;

	result = c;
	if (c >= 'a' && c <= 'z')
	{
		result = c - ('a' - 'A');
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void) {
    char c;

    c = 'm';
    printf("%c -> %c", c, ft_toupper(c));

    c = 'L';
    printf("\n%c -> %c", c, ft_toupper(c));

    c = '\0';
    printf("\n%c -> %c", c, ft_toupper(c));
    return (0);
}
*/
