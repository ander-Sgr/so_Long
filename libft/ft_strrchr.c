/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:02:22 by aestrell          #+#    #+#             */
/*   Updated: 2024/01/28 19:02:22 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*found_last;
	int			i;

	found_last = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			found_last = &s[i];
		}
		i++;
	}
	if (s[i] == (char)c)
		found_last = &s[i];
	return ((char *)(found_last));
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*cadena;
	char		caracter;
	char		*resultado;

	cadena = "Hola MundoH";
	caracter = 'H';
	resultado = ft_strrchr(cadena, caracter);
	if (resultado != NULL)
	{
		printf("Última aparición de '%c' encontrada en la posición: %ld\n",
				caracter,
				resultado - cadena);
	}
	else
	{
		printf("El carácter '%c' no se encontró en la cadena.\n", caracter);
	}
	return (0);
}
*/
