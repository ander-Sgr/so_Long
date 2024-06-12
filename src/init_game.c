/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:30:25 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/13 00:39:20 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_mlx(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (game->mlx.mlx_ptr == NULL)
	{
		printf("Error: Some occurred for init the game\n");
		ft_end_game(game);
	}
}
static void	ft_init_window(t_game *game)
{
	int	tile_width;
	int	tile_height;

	tile_width = game->map.width * TILE_SIZE;
	tile_height = game->map.height * TILE_SIZE;
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, tile_width,
			tile_height, "so_long");
	if (game->mlx.win_ptr == NULL)
	{
		mlx_destroy_display(game->mlx.mlx_ptr);
		printf("Error: Can't create window\n");
		free(game->mlx.mlx_ptr);
		ft_end_game(game);
	}
}

void	ft_start_game(t_game *game, char *file_map)
{
	if (!ft_init_vars(game))
	{
		printf("Error initializing variables\n");
		ft_end_game(game);
	}
	ft_init_mlx(game);
	if (!ft_init_map(file_map, game))
	{
		printf("Error initialiing map\n");
		ft_end_game(game);
	}
	ft_init_window(game);
	if (ft_init_images(game) && ft_draw_map(game))
	{
		mlx_key_hook(game->mlx.win_ptr, handle_keypress, game);
		mlx_hook(game->mlx.win_ptr, ClientMessage, LeaveWindowMask, ft_end_game,
				game);
		mlx_loop(game->mlx.mlx_ptr);
	}
	else
	{
		printf("Error: An Ocurred for initializing game\n");
		ft_end_game(game);
	}
}
