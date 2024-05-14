/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:46:42 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/14 17:17:26 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_mlx *mlx, t_map *map)
{
	char	*file_name;
	int		map_x;
	int		map_y;

	//int		tile_width;
	//int		tile_height;
	int i, j;
	// Calcular el tamaño de cada celda del mapa
	//tile_width = WIN_WIDTH / map->width;
	// tile_height = WIN_HEIGHT / map->height;
	// Iterar sobre cada celda del mapa
	for (i = 0; i < map->height; i++)
	{
		for (j = 0; j < map->width; j++)
		{
			map_x = j;
			map_y = i;
			// Si la celda es un bloque, dibuja el XPM en esa posición
			if (map->map[i][j] == '1')
				file_name = "./textures/wall.xpm";
			else if (map->map[i][j] == '0')
				file_name = "./textures/floor.xpm";
			draw_xpm(mlx, file_name, map_x, map_y);
		}
	}
}
