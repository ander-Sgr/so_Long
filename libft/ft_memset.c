/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:43:09 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/15 23:08:32 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp_ptr;
	unsigned char	temp_c;
	size_t			i;

	i = 0;
	temp_ptr = s;
	temp_c = c;
	while (i < n)
	{
		temp_ptr[i] = temp_c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>
int	main(void)
{
	char	s[10];
	char	c;

	c = 'a';
	ft_memset(s, c, 5);
	printf("\ns -> contents: %s\n", s);
	ft_memset(s + 5, 'b', 4);
	printf("\ns ->  contents: %s\n", s);
}
*/
