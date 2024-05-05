/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:34:56 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/16 17:32:43 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_substr(void)
{
	char	*substr;

	substr = (char *)malloc(sizeof(char));
	if (substr == NULL)
		return (NULL);
	substr[0] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substr = check_substr();
		return (substr);
	}
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*cadena;
	char		*result;

	cadena = "hola a todos";
	result = ft_substr(cadena, 3, 16);
	printf("result : %s", result);
	free(result);
}
*/
