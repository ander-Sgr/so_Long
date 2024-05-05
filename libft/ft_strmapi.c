/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:25:18 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/13 21:25:18 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	len;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
#include <stdio.h>

char	f(unsigned int index, char s)
{
    printf("the char %c is in the pos> %d\n ", s, index);
     if (s >= 'a' && s <= 'z') {
        return (s - ('a' - 'A'));
    } else {
        return (s);
    }
}
int	main(void)
{
	char	str[10];
	char	*result;

	str[10] = "hello.";
	printf("The result is %s\n", str);
	result = ft_strmapi(str, &f);
	printf("The result is %s\n", result);
	return (0);
}
*/
