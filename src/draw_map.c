/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:46:42 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/11 00:28:53 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_elements(t_game *game, int x, int y)
{
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
	{
		if (game->map.item_count == game->player.items_recollected)
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
					game->exit.img_ptr, y * TILE_SIZE, x * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
					game->closed_door.img_ptr, y * TILE_SIZE, x * TILE_SIZE);
	}
}

static int	ft_is_valid_element(t_game *game, char element)
{
	char	*valid_elements;

	valid_elements = "10PCE";
	if (element == 'P')
		game->map.character_count++;
	if (element == 'E')
		game->map.exit_count++;
	if (element == 'C')
		game->map.item_count++;
	if (!strchr(valid_elements, element))
	{
		printf("Error: elements on the map are \
			not valid! verify just content 10PCE\n");
		return (0);
	}
	return (1);
}

int	ft_check_elements_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (game->map.map[i][j] != '\0' && game->map.map[i][j] != '\n')
		{
			if (!ft_is_valid_element(game, game->map.map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (game->map.character_count > 1 || game->map.exit_count > 1)
	{
		printf("Error: Verify the number of players & exits:\n");
		return (0);
	}
	return (1);
}

static int	ft_check_number_elements(t_game *game)
{
	if (game->map.character_count < 1 || game->map.exit_count < 1
		|| game->map.item_count < 1)
	{
		printf("Error: The should contain \
		a minimum 1 player 1 exit & 1 item\n");
		return (0);
	}
	return (1);
}

int	ft_draw_map(t_game *game)
{
	int	i;
	int	j;

	if (!ft_check_elements_map(game))
		return (0);
	if (!ft_check_number_elements(game))
		return (0);
	if (!ft_check_pathfinder(game, &game->player.pos_player))
		return (0);
	i = 0;
	ft_element_pos(game);
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			ft_draw_elements(game, i, j);
			j++;
		}
		i++;
	}
	printf("item_count_ draw map %d\n", game->map.item_count);
	printf("item_count_ draw map %d\n", game->player.items_recollected);
	return (1);
}
