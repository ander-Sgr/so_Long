/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:24:55 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/01 20:24:55 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*temp_s1;
	const unsigned char	*temp_s2;

	i = 0;
	temp_s1 = s1;
	temp_s2 = s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (temp_s1[i] != temp_s2[i])
			return (temp_s1[i] - temp_s2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void) {
    const char *cadena1 = "Hola";
    const char *cadena2 = "Hola";
    int resultado1 = ft_memcmp(cadena1, cadena2, 0);
    printf("Ejemplo 1: %d\n", resultado1);

    const char *cadena3 = "Hola";
    const char *cadena4 = "Mundo";
    int resultado2 = ft_memcmp(cadena3, cadena4, 0);
    printf("Ejemplo 2: %d\n", resultado2);

    int bloque1[] = {1, 2, 3, 4};
    int bloque2[] = {1, 2, 5, 4};
    int resultado3 = ft_memcmp(bloque1, bloque2, sizeof(bloque1));
    printf("Ejemplo 3: %d\n", resultado3);

}
*/
