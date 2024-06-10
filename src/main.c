/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:35:01 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/10 19:43:57 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	game;
	int		tile_width;
	int		tile_height;
	char	*file_map;

	file_map = "./maps/map1.ber";
	ft_init_vars(&game);
	game.mlx.mlx_ptr = mlx_init();
	if (game.mlx.mlx_ptr == NULL)
		printf("Error initializing MLX\n");
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
		if (ft_init_images(&game) && ft_draw_map(&game))
		{
			mlx_key_hook(game.mlx.win_ptr, handle_keypress, &game);
			mlx_loop(game.mlx.mlx_ptr);
		}
	}
}
