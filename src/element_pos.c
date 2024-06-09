/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:28:12 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/09 20:17:13 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pos_player(t_game *game, int i, int j)
{
	game->player.pos_player.x = i;
	game->player.pos_player.y = j;
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
