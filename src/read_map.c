/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:01:06 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/06 22:11:37 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_get_map_dimensions(char *file_map, t_game *game)
{
	int		fd;
	int		height;
	char	*line;
	int		width;

	width = 0;
	height = 0;
	fd = open(file_map, O_RDONLY);
	if (fd <= 0)
		return ;
	while (file_map != NULL && line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		width = strlen(line);
		height++;
		free(line);
	}
	close(fd);
	game->map.width = width;
	game->map.height = height;
}

static char	**ft_read_map(char *file_map, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_map, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	game->map.map = (char **)malloc(sizeof(char *) * game->map.height);
	if (game->map.map == NULL)
	{
		close(fd);
		return (NULL);
	}
	i = 0;
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		if (line)
			game->map.map[i] = strdup(line);
		free(line);
		i++;
	}
	close(fd);
	return (game->map.map);
}

void	ft_cleanup_map(t_game *game)
{
	int	i;

	if (game->map.map)
	{
		i = 0;
		while (i < game->map.height)
		{
			if (game->map.map[i])
				free(game->map.map[i]);
			i++;
		}
		free(game->map.map);
		game->map.map = NULL;
	}
}

t_game	*ft_init_map(char *file_map, t_game *game)
{
	int		found_exit;
	t_pos	start_pos;

	game->map.map = NULL;
	ft_get_map_dimensions(file_map, game);
	game->map.map = ft_read_map(file_map, game);
	ft_element_pos(game);
	if (game->map.map == NULL || !ft_is_valid_map(game, file_map))
	{
		ft_cleanup_map(game);
		return (NULL);
	}
	printf("Pos en init map x %d - y %d\n", game->player.pos_player.x,
			game->player.pos_player.y);
	start_pos = game->player.pos_player;
	found_exit = flood_fill(game, &start_pos);
	printf("%d", found_exit);
	if (!found_exit)
	{
		printf("Error: no se pudo encontrar la salida en el mapa.\n");
		ft_cleanup_map(game);
		return (NULL);
	}
	return (game);
}
