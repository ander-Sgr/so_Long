/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:46:42 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/12 20:54:48 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_map(t_mlx *mlx, t_map *map) {
    int tile_width;
    int tile_height;
    int i, j;

    // Calcular el tamaño de cada celda del mapa
    tile_width = WIN_WIDTH / map->width;
    tile_height = WIN_HEIGHT / map->height;

    // Iterar sobre cada celda del mapa
    for (i = 0; i < map->height; i++) {
        for (j = 0; j < map->width; j++) {
            int map_x = j * tile_width;
            int map_y = i * tile_height;

            // Si la celda es un bloque, dibuja el XPM en esa posición
            if (map->map[i][j] == '1') {
                draw_xpm(mlx, "./textures/wall.xpm", map_x, map_y); // Cambia "bloque.xpm" por tu archivo XPM
            }
        }
    }
}
