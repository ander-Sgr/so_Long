/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:35:01 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/11 19:36:17 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

int	main(void)
{
    t_map map;
    char *file_name = "./maps/map1.ber";

    ft_get_map_dimensions(file_name, &map);
    map.map = ft_read_map(file_name, &map);

    if (map.map == NULL) {
        printf("Error al leer el mapa\n");
        return 1;
    }

    printf("Ancho del mapa: %d\n", map.width);
    printf("Altura del mapa: %d\n", map.height);
    printf("Contenido del mapa:\n");
    for (int y = 0; y < map.height; y++) {
        for (int x = 0; x < map.width; x++) {
            printf("%c ", map.map[y][x]);
        }
        printf("\n");
    }

    // Liberar memoria utilizada para almacenar el mapa
    for (int i = 0; i < map.height; i++) {
        free(map.map[i]);
    }
    free(map.map);

    return 0;
}
