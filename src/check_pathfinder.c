/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pathfinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:23:14 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/06 18:52:13 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// todo  a func for verify a valid path for end the game
static int	is_valid_position(t_game *game, t_pos *pos)
{
	if (pos->x >= 0 && pos->x < game->map.height && pos->y >= 0
		&& pos->y < game->map.width)
		return (1);
	return (0);
}

static int	is_passable_cell(t_game *game, t_pos *pos)
{
	if (game->map.map[pos->x][pos->y] == '0'
		|| game->map.map[pos->x][pos->y] == 'C'
		|| game->map.map[pos->x][pos->y] == 'E'
		|| game->map.map[pos->x][pos->y] == 'P')
		return (1);
	printf("Impassable cell at x: %d, y: %d, cell: %c\n", pos->x, pos->y,
			game->map.map[pos->x][pos->y]);
	return (0);
}
