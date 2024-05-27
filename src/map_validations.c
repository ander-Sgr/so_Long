/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:07:06 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/27 20:49:34 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_valid_ext(char *file_map)
{
	char	dot;
	char	*ext;
	char	*result;

	dot = '.';
	ext = ".ber";
	if (file_map == NULL)
		return (0);
	result = strrchr(file_map, dot);
	if (result != NULL && strcmp(ext, result) == 0)
	{
		return (1);
	}
	return (0);
}
/*
void	ft_is_valid_map(char element, t_game *game)
{

} */

// to do verifiar la estructura del mapa por ej 1ra  linea es vacia o no
