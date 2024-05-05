/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:15:36 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/06 23:15:36 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_join;
	size_t	i;
	size_t	j;
	size_t	total_size;

	total_size = ft_strlen(s1) + ft_strlen(s2);
	result_join = (char *)malloc((total_size + 1) * sizeof(char));
	if (result_join == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result_join[i] = s2[j];
		i++;
		j++;
	}
	result_join[i] = '\0';
	return (result_join);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*cadena1;
	const char	*cadena2;
	char		*result;

    cadena1 = "hola";
    cadena2 = "mundo!";
    result = ft_strjoin(cadena1, cadena2);
    printf("result : %s", result);
	free(result);
}
*/
