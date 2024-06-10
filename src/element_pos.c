/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:28:12 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/10 19:50:09 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pos_player(t_game *game, int i, int j)
{
	game->player.pos_player.x = j;
	game->player.pos_player.y = i;
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
			j++;
		}
		i++;
	}
	return (game);
}

void	ft_update_player_position(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = game->player.pos_player.x;
	old_y = game->player.pos_player.y;
	game->map.map[old_y][old_x] = '0';
	ft_draw_elements(game, old_y, old_x);
	game->player.pos_player.x = new_x;
	game->player.pos_player.y = new_y;
	game->map.map[new_y][new_x] = 'P';
	ft_draw_elements(game, new_y, new_x);
}
