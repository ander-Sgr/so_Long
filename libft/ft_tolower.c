/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:21:32 by aestrell          #+#    #+#             */
/*   Updated: 2024/01/25 19:21:32 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	result;

	result = c;
	if (c >= 'A' && c <= 'Z')
	{
		result = c - ('A' - 'a');
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void) {
    char c;

    c = 'H';
    printf("%c -> %c", c, ft_tolower(c));

    c = 'p';
    printf("\n%c -> %c", c, ft_tolower(c));

    c = '5';
    printf("\n%c -> %c", c, ft_tolower(c));
    return (0);
}
*/
