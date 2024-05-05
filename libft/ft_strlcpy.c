/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:33:42 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/16 00:24:31 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	size_src;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	size_src = ft_strlen(src);
	return (size_src);
}

/*
#include <stdio.h>
int	main(void) {
    char destino[13];
    char *origen = "Hola, mundo!";
    
    size_t tamano_destino = sizeof(destino);
    
    size_t resultado = ft_strlcpy(destino, origen, tamano_destino);
    
    // Imprimir el resultado
    printf("Cadena copiada: %s\n", destino);
    printf("Longitud total después de la copia: %zu\n", resultado);

    return (0);
}
*/
