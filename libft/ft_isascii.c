/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:00:47 by aestrell          #+#    #+#             */
/*   Updated: 2024/01/11 18:00:47 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 0 127

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
		return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int c;

	c = 6565;
	if (ft_isascii(c))
	{
		printf("%c\n", c);
	}
    else
        printf("no ascii");
}
*/
