/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:07:06 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/29 19:13:39 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_valid_ext(char *file_map)
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

static int	ft_check_map_format(t_game *game)
{
	int	i;
	int	j;
	int	len_line;

	i = 0;
	while (i < game->map.height)
	{
		len_line = strlen(game->map.map[i]);
		if (len_line != game->map.width + 1 &&
			game->map.map[i][len_line - 1] == '\n')
			return (0);
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
static int	ft_check_borders_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (i == 0 || j == 0 || j == game->map.width - 1
				|| i == game->map.height - 1)
			{
				if (game->map.map[i][j] == '1')
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_valid_map(t_game *game, char *file_map)
{
	if (!ft_is_valid_ext(file_map))
	{
		printf("Error: Verify the type of file\n");
		return (0);
	}
	if (!ft_check_map_format(game))
	{
		printf("Error: Invalid map!\n");
		return (0);
	}
	if (!ft_check_borders_map(game))
	{
		printf("Error: The map should be sorrounded by walls\n");
		return (0);
	}
	return (1);
}
/*
	todo una funcion que haga todas las comprobaciones..
	if (el formato de mapa es true) if (la ext es true) etc etc

¡*/
