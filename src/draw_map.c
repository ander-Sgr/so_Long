/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:46:42 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/17 00:42:08 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// x - width
// y - height

static void	ft_check_elements_map(t_game *game, int x, int y)
{
}

void	ft_draw_map(t_game *game)
{
	char	*file_name;
	int		i;
	int		j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == '1')
				file_name = "./textures/wall.xpm";
			else if (game->map.map[i][j] == '0')
				file_name = "./textures/floor.xpm";
			draw_xpm(game->mlx, file_name, j, i);
			j++;
		}
		i++;
	}
}
