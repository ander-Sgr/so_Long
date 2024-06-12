/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:58:37 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/13 01:21:29 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_show_move_counter(t_game *game)
{
	printf("You have taken a total of %d steps\n", game->player.mov_count);
}

int	ft_move_handle_keypress(int keycode, int *new_x, int *new_y)
{
	int	moved;

	moved = 0;
	if (keycode == K_W)
	{
		(*new_y)--;
		moved = 1;
	}
	else if (keycode == K_S)
	{
		(*new_y)++;
		moved = 1;
	}
	else if (keycode == K_A)
	{
		(*new_x)--;
		moved = 1;
	}
	else if (keycode == K_D)
	{
		(*new_x)++;
		moved = 1;
	}
	return (moved);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;
	int	moved;

	new_x = game->player.pos_player.x;
	new_y = game->player.pos_player.y;
	moved = 0;
	moved = ft_move_handle_keypress(keycode, &new_x, &new_y);
	if (keycode == K_ESC)
	{
		ft_end_game(game);
		exit(EXIT_SUCCESS);
	}
	if (game->map.map[new_y][new_x] != '1' && moved)
	{
		game->player.mov_count++;
		ft_show_move_counter(game);
		ft_update_player_position(game, new_x, new_y);
	}
	return (0);
}
