/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:37:27 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/13 01:19:30 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_init_map_vars(t_game *game)
{
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.character_count = 0;
	game->map.exit_count = 0;
	game->map.item_count = 0;
	game->map.found_exit = 0;
	game->map.collected_item = 0;
	return (1);
}

static int	ft_init_mlx_vars(t_game *game)
{
	game->mlx.mlx_ptr = NULL;
	game->mlx.win_ptr = NULL;
	return (1);
}

static int	ft_init_player_vars(t_game *game)
{
	game->player.pos_player.x = 0;
	game->player.pos_player.y = 0;
	game->player.items_recollected = 0;
	game->player.mov_count = 0;
	game->player.current_tile = ' ';
	return (1);
}

static int	ft_init_images_vars(t_game *game)
{
	if (!ft_init_wall(game))
		return (0);
	if (!ft_init_floor(game))
		return (0);
	if (!ft_init_character(game))
		return (0);
	if (!ft_init_item(game))
		return (0);
	if (!ft_init_exit(game))
		return (0);
	return (1);
}

int	ft_init_vars(t_game *game)
{
	if (!ft_init_mlx_vars(game))
		return (0);
	if (!ft_init_player_vars(game))
		return (0);
	if (!ft_init_map_vars(game))
		return (0);
	if (!ft_init_images_vars(game))
		return (0);
	return (1);
}
