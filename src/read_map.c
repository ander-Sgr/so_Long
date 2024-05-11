/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:01:06 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/11 19:33:33 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map_dimensions(char *file_map, t_map *map)
{
	int		fd;
	int		max_width;
	int		height;
	char	*line;
	int		width;

	max_width = 0;
	height = 0;
	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		return ;
	while (file_map != NULL && line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		width = strlen(line);
		if (width > max_width)
			max_width = width;
		height++;
		free(line);
	}
	close(fd);
	map->width = max_width;
	map->height = height;
}

char	**ft_read_map(char *file_map, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map->map = (char **)malloc(sizeof(char *) * map->height);
	if (map->map == NULL)
	{
		close(fd);
		return (NULL);
	}
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->map[i++] = strdup(line);
		free(line);
	}
	close(fd);
	return (map->map);
}
