/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:10:39 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/16 16:09:04 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp_ptr;
	size_t	i;

	i = 0;
	temp_ptr = s;
	while (i < n)
	{
		temp_ptr[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h>

int	main(void) {
    char *s = "Hello, World!";
    printf("before ft_bzero: %s\n", s);
	ft_bzero(s, 4);
    printf("after ft_bzero: %s\n", s);
}
*/
