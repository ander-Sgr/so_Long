/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:32:21 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/16 19:04:49 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*new_str;

	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void) {
    const char *original = "Hola, mundo";
    char *copia = ft_strdup(original);
    if (copia == NULL) {
        printf("Error");
    }
    printf("Original: %s\n", original);
    printf("Copia:    %s\n", copia);
    free(copia);

    return (0);
}
*/
