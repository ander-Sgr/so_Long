/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:23:18 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/15 23:00:20 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
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
	int c = 0;

	while (c <= 127)
	{
		if (ft_isprint(c))
		{
			printf("printable chars %c\n", c);
		}
		else
			printf("nonprintables chars %c\n", c);
		c++;
	}
}
*/
