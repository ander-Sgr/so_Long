/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:41:12 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/15 23:44:56 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*temp_ptr_src;
	unsigned char		*temp_ptr_dest;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	temp_ptr_src = src;
	temp_ptr_dest = dest;
	while (i < n)
	{
		temp_ptr_dest[i] = temp_ptr_src[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*src;
	char	dest[20];
	char	*result;

	src = "bon dia";
	result = (char *)ft_memcpy(dest, src, ft_strlen(src));
	printf("src %s\n", src);
	printf("destination %s\n", dest);
	if (result == dest)
		printf("done");
	else
		printf("faild");
}
*/
