/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:25:58 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/15 22:57:33 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'))
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
    char    c;

    c = 'A';
	if (ft_isalnum(c))
		printf("is alphanum");
	else
		printf("not alpha");
}
*/
