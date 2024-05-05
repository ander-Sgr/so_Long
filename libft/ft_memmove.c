/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:20:52 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/16 00:18:20 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*dest_ptr;
	char	*src_ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	i = 0;
	if (src_ptr < dest_ptr)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dest_ptr[i] = src_ptr[i];
		}
	}
	else
	{
		ft_memcpy(dest, src, len);
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	src[20];

	src[20] = "Hello, World!";
	// Copiar los primeros 10 caracteres de src a src (solapamiento)
	ft_memmove(src, src + 5, 10);
	printf("%s\n", src);
	return (0);
}
*/
