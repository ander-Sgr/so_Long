/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:46:42 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/22 02:13:44 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_elements_map(t_game *game, int x, int y)
{
	printf("siii");
	if (game->map.map[x][y] == '1')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
				game->wall.img_ptr, y * TILE_SIZE, x * TILE_SIZE);
	else if (game->map.map[x][y] == '0')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
				game->floor.img_ptr, y * TILE_SIZE, x * TILE_SIZE);
	else if (game->map.map[x][y] == 'P')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
				game->character.img_ptr, y * TILE_SIZE, x * TILE_SIZE);
	else if (game->map.map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
				game->item.img_ptr, y * TILE_SIZE, x * TILE_SIZE);
	else if (game->map.map[x][y] == 'E')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
				game->exit.img_ptr, y * TILE_SIZE, x * TILE_SIZE);
}

void	ft_draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			ft_check_elements_map(game, i, j);
			j++;
		}
		i++;
	}
}
