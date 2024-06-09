/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:43:16 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/09 19:48:29 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_wall(t_game *game)
{
	game->wall.img_ptr = NULL;
	game->wall.img_path = NULL;
	game->wall.addr = NULL;
	game->wall.width = 0;
	game->wall.heigth = 0;
	game->wall.tile_size = 0;
	game->wall.bits_per_pixel = 0;
	game->wall.size_line = 0;
	game->wall.endian = 0;
}

void	ft_init_floor(t_game *game)
{
	game->floor.img_ptr = NULL;
	game->floor.img_path = NULL;
	game->floor.addr = NULL;
	game->floor.width = 0;
	game->floor.heigth = 0;
	game->floor.tile_size = 0;
	game->floor.bits_per_pixel = 0;
	game->floor.size_line = 0;
	game->floor.endian = 0;
}

void	ft_init_character(t_game *game)
{
	game->character.img_ptr = NULL;
	game->character.img_path = NULL;
	game->character.addr = NULL;
	game->character.width = 0;
	game->character.heigth = 0;
	game->character.tile_size = 0;
	game->character.bits_per_pixel = 0;
	game->character.size_line = 0;
	game->character.endian = 0;
}

void	ft_init_item(t_game *game)
{
	game->item.img_ptr = NULL;
	game->item.img_path = NULL;
	game->item.addr = NULL;
	game->item.width = 0;
	game->item.heigth = 0;
	game->item.tile_size = 0;
	game->item.bits_per_pixel = 0;
	game->item.size_line = 0;
	game->item.endian = 0;
}

void	ft_init_exit(t_game *game)
{
	game->exit.img_ptr = NULL;
	game->exit.img_path = NULL;
	game->exit.addr = NULL;
	game->exit.width = 0;
	game->exit.heigth = 0;
	game->exit.tile_size = 0;
	game->exit.bits_per_pixel = 0;
	game->exit.size_line = 0;
	game->exit.endian = 0;
}
