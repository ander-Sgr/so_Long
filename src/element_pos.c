/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:28:12 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/13 01:05:22 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_pos_player(t_game *game, int i, int j)
{
	game->player.pos_player.x = j;
	game->player.pos_player.y = i;
}

static void	ft_pos_exit(t_game *game, int i, int j)
{
	game->map.exit_pos.x = j;
	game->map.exit_pos.y = i;
}

t_game	*ft_element_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (game->map.map[i][j] != '\0' && game->map.map[i][j] != '\n')
		{
			if (game->map.map[i][j] == 'P')
				ft_pos_player(game, i, j);
			if (game->map.map[i][j] == 'E')
				ft_pos_exit(game, i, j);
			j++;
		}
		i++;
	}
	return (game);
}

static void	ft_load_exit(t_game *game)
{
	if (game->player.current_tile == 'C')
	{
		game->player.items_recollected++;
		if (game->map.item_count == game->player.items_recollected)
		{
			ft_draw_elements(game, game->map.exit_pos.y, game->map.exit_pos.x);
		}
	}
}

void	ft_update_player_position(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = game->player.pos_player.x;
	old_y = game->player.pos_player.y;
	if (game->map.map[old_y][old_x] == 'P' && game->player.current_tile == 'E')
		game->map.map[old_y][old_x] = 'E';
	else
		game->map.map[old_y][old_x] = '0';
	ft_draw_elements(game, old_y, old_x);
	game->player.pos_player.x = new_x;
	game->player.pos_player.y = new_y;
	game->player.current_tile = game->map.map[new_y][new_x];
	game->map.map[new_y][new_x] = 'P';
	ft_draw_elements(game, new_y, new_x);
	ft_load_exit(game);
	if (game->player.current_tile == 'E'
		&& game->map.item_count == game->player.items_recollected)
		ft_end_game(game);
}
