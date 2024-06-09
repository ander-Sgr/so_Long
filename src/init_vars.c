/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:37:27 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/09 20:05:25 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_map_vars(t_game *game)
{
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.character_count = 0;
	game->map.exit_count = 0;
	game->map.item_count = 0;
	game->map.found_exit = 0;
	game->map.collected_item = 0;
}

static void	ft_init_mlx_vars(t_game *game)
{
	game->mlx.mlx_ptr = NULL;
	game->mlx.win_ptr = NULL;
}

static void	ft_init_player_vars(t_game *game)
{
	game->player.pos_player.x = 0;
	game->player.pos_player.y = 0;
	game->player.items_recollected = 0;
	game->player.mov_count = 0;
}
static void	ft_init_images_vars(t_game *game)
{
	ft_init_wall(game);
	ft_init_floor(game);
	ft_init_character(game);
	ft_init_item(game);
	ft_init_exit(game);
}

void	ft_init_vars(t_game *game)
{
	ft_init_mlx_vars(game);
	ft_init_player_vars(game);
	ft_init_map_vars(game);
	ft_init_images_vars(game);
}
