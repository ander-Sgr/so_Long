/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:35:01 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/06 22:02:04 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_pos(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
}

void	initialize_game(t_game *game)
{
	// Inicialización de las estructuras básicas
	game->mlx.mlx_ptr = NULL;
	game->mlx.win_ptr = NULL;
	game->player.pos_player.x = 0;
	game->player.pos_player.y = 0;
	game->player.items_recollected = 0;
	game->player.mov_count = 0;
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.character_count = 0;
	game->map.exit_count = 0;
	game->map.item_count = 0;
	game->map.found_exit = 0;
	game->map.collected_item = 0;
	// Inicialización de las imágenes (sin cargar aún)
	game->wall.img_ptr = NULL;
	game->wall.addr = NULL;
	game->floor.img_ptr = NULL;
	game->floor.addr = NULL;
	game->character.img_ptr = NULL;
	game->character.addr = NULL;
	game->item.img_ptr = NULL;
	game->item.addr = NULL;
	game->exit.img_ptr = NULL;
	game->exit.addr = NULL;
}
int	main(void)
{
	t_game	game;
	t_pos	pos;
	int		tile_width;
	int		tile_height;
	char	*file_map;

	file_map = "./maps/map1.ber";
	// Inicializar el juego
	initialize_game(&game);
	init_pos(&pos);
	// Inicializar MLX
	game.mlx.mlx_ptr = mlx_init();
	if (game.mlx.mlx_ptr == NULL)
	{
		printf("Error initializing MLX\n");
	}
	// Inicializar el mapa
	if (ft_init_map(file_map, &game))
	{
		tile_width = game.map.width * TILE_SIZE;
		tile_height = game.map.height * TILE_SIZE;
		game.mlx.win_ptr = mlx_new_window(game.mlx.mlx_ptr, tile_width,
				tile_height, "so_long");
		if (game.mlx.win_ptr == NULL)
		{
			printf("Error creating window\n");
			free(game.mlx.mlx_ptr);
		}
		// Inicializar imágenes & mapa
		if (ft_init_images(&game) && ft_draw_map(&game))
		{
			printf("\nwidth %d - heigth %d\n", game.map.width, game.map.height);
			mlx_loop(game.mlx.mlx_ptr);
		}
	}
}
