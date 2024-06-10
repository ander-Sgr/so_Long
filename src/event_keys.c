/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:58:37 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/10 19:36:41 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player.pos_player.x;
	new_y = game->player.pos_player.y;
	if (keycode == K_ESC)
	{
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == K_W)
		new_y -= 1;
	else if (keycode == K_S)
		new_y += 1;
	else if (keycode == K_A)
		new_x -= 1;
	else if (keycode == K_D)
		new_x += 1;
	if (game->map.map[new_y][new_x] != '1')
	{
		game->player.mov_count++;
		ft_update_player_position(game, new_x, new_y);
	}
	return (0);
}
