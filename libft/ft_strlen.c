/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:15:06 by aestrell          #+#    #+#             */
/*   Updated: 2024/01/13 11:15:06 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*ptr;
	size_t	size;

 
    ptr = "test length fdsfsdfwer23r23e23e3";
    size = ft_strlen(ptr);
    printf("%d", size);
}
*/
