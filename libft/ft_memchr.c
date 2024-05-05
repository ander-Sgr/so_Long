/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:41:44 by aestrell          #+#    #+#             */
/*   Updated: 2024/01/30 20:41:44 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*temp_str;
	unsigned char		temp_c;

	i = 0;
	temp_str = s;
	temp_c = c;
	while (i < n)
	{
		if (temp_str[i] == temp_c)
		{
			return ((void *)&temp_str[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <stdlib.h>

void	run_test(const void *s, int c, size_t n) {
    void *result = ft_memchr(s, c, n);
    if (result != NULL) {
        printf("Carácter encontrado en la posición %lld\n",
		(unsigned char *)result - (unsigned char *)s);
    } else {
        printf("Carácter no encontrado\n");
    }
}

int	main(void) {
    const char *cadena = "Hola, mundo!";
    
    // Test 1: Buscar 'o' en la cadena completa
    run_test(cadena, 'o', 13);

    // Test 2: Buscar 'z' en la cadena completa
    run_test(cadena, 'z', 13);

    // Test 3: Buscar 'm' en los primeros 5 caracteres
    run_test(cadena, 'm', 5);

    // Test 4: Buscar 'H' en los primeros 5 caracteres
    run_test(cadena, 'H', 5);

    // Test 5: Buscar '\0' (carácter nulo) en la cadena completa
    run_test(cadena, '\0', 13);

    return (0);
}
*/
