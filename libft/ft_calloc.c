/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:11:18 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/05 18:11:18 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	while (i < count * size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void) {
    size_t num_elements = 5;
    size_t size_of_element = sizeof(int);

    // Asignar un bloque de memoria para 5 enteros e inicializar a cero
    int *arr = (int *)ft_calloc(num_elements, size_of_element);

    if (arr == NULL) {
        fprintf(stderr, "Error al asignar memoria con calloc.\n");
        return (1);
    }

    // Imprimir los elementos del array (deberían ser 0)
    printf("Array después de calloc:\n");
    for (size_t i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Liberar la memoria asignada
    free(arr);

    return (0);
}
*/
