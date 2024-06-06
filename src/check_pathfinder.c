/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pathfinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:23:14 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/06 22:11:58 by aestrell         ###   ########.fr       */
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

static void	recursive_path_search(t_game *game, t_pos *pos, int **visited)
{
	t_pos	directions[4];
	int		i;

	//	int		current_count_items;
	if (!is_valid_position(game, pos) || visited[pos->x][pos->y] ||
		!is_passable_cell(game, pos))
		return ;
	visited[pos->x][pos->y] = 1;
	if (game->map.map[pos->x][pos->y] == 'E')
		game->map.found_exit = 1;
	directions[0] = (t_pos){pos->x + 1, pos->y};
	directions[1] = (t_pos){pos->x - 1, pos->y};
	directions[2] = (t_pos){pos->x, pos->y + 1};
	directions[3] = (t_pos){pos->x, pos->y - 1};
	i = 0;
	while (i < 4)
	{
		recursive_path_search(game, &directions[i], visited);
		i++;
	}
}

int	flood_fill(t_game *game, t_pos *start_pos)
{
	int	**visited;
	int	found_exit;
	int	total_item;

	// 	int	i;
	total_item = game->map.collected_item;
	found_exit = 0;
	visited = (int **)malloc(game->map.height * sizeof(int *));
	for (int i = 0; i < game->map.height; i++)
		visited[i] = (int *)calloc(game->map.width, sizeof(int));
	printf("total item %d\n.", total_item);
	recursive_path_search(game, start_pos, visited);
	if (game->map.found_exit != 0)
	{
		found_exit = 1;
	}
	for (int i = 0; i < game->map.height; i++)
		free(visited[i]);
	free(visited);
	return (found_exit);
}
