/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:56:14 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/13 21:59:30 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_xpm(t_game *game)
{
	if (game->wall.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->wall.img_ptr);
	if (game->floor.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->floor.img_ptr);
	if (game->item.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->item.img_ptr);
	if (game->exit.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->exit.img_ptr);
	if (game->closed_door.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->closed_door.img_ptr);
	if (game->character.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->character.img_ptr);
}

void	ft_mlx_closing(t_game *game)
{
	ft_destroy_xpm(game);
	if (game->mlx.win_ptr)
	{
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
		game->mlx.win_ptr = NULL;
	}
	if (game->mlx.mlx_ptr)
	{
		mlx_destroy_display(game->mlx.mlx_ptr);
		free(game->mlx.mlx_ptr);
		game->mlx.mlx_ptr = NULL;
	}
}
int	ft_end_game(t_game *game)
{
	if (game)
	{
		ft_mlx_closing(game);
		ft_cleanup_map(game);
		free(game);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
