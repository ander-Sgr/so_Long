/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pathfinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:23:14 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/11 22:20:08 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_valid_position(t_game *game, t_pos *pos)
{
	if (pos->x >= 0 && pos->x < game->map.width && pos->y >= 0
		&& pos->y < game->map.height)
		return (1);
	return (0);
}

static int	ft_is_passable_cell(t_game *game, t_pos *pos)
{
	if (game->map.map[pos->y][pos->x] == '0'
		|| game->map.map[pos->y][pos->x] == 'C'
		|| game->map.map[pos->y][pos->x] == 'E'
		|| game->map.map[pos->y][pos->x] == 'P')
		return (1);
	return (0);
}

static void	ft_recursive_path_search(t_game *game, t_pos *pos, int **visited)
{
	t_pos	directions[4];
	int		i;

	if (!ft_is_valid_position(game, pos) || visited[pos->y][pos->x] ||
		!ft_is_passable_cell(game, pos))
		return ;
	visited[pos->y][pos->x] = 1;
	if (game->map.map[pos->y][pos->x] == 'E')
		game->map.found_exit = 1;
	if (game->map.map[pos->y][pos->x] == 'C')
		game->map.collected_item++;
	directions[0] = (t_pos){pos->x + 1, pos->y};
	directions[1] = (t_pos){pos->x - 1, pos->y};
	directions[2] = (t_pos){pos->x, pos->y + 1};
	directions[3] = (t_pos){pos->x, pos->y - 1};
	i = 0;
	while (i < 4)
	{
		ft_recursive_path_search(game, &directions[i], visited);
		i++;
	}
}

void	ft_clean_visited_pos(t_game *game, int **visited)
{
	int	i;

	i = 0;
	while (i < game->map.height)
		free(visited[i++]);
	free(visited);
}

int	ft_check_pathfinder(t_game *game, t_pos *start_pos)
{
	int	**visited;
	int	valid_path;
	int	i;

	valid_path = 1;
	visited = (int **)malloc(game->map.height * sizeof(int *));
	if (!visited)
		return (0);
	i = 0;
	while (i < game->map.height)
	{
		visited[i] = (int *)calloc(game->map.width, sizeof(int));
		if (!visited[i])
		{
			ft_clean_visited_pos(game, visited);
			return (0);
		}
		i++;
	}
	ft_recursive_path_search(game, start_pos, visited);
	if (!ft_validate_path(game, game->map.item_count, game->map.exit_count))
		valid_path = 0;
	ft_clean_visited_pos(game, visited);
	return (valid_path);
}
