/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:07:06 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/16 14:40:40 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_valid_ext(char *file_map)
{
	char	dot;
	char	*ext;
	char	*result;

	dot = '.';
	ext = ".ber";
	if (file_map == NULL)
		return (0);
	result = ft_strrchr(file_map, dot);
	if (result != NULL && ft_strncmp(ext, result, ft_strlen(ext) + 1) == 0)
	{
		return (1);
	}
	return (0);
}

static int	ft_check_map_format(t_game *game)
{
	int	i;
	int	j;
	int	len_line;

	i = 0;
	while (i < game->map.height)
	{
		len_line = ft_strlen(game->map.map[i]);
		if (len_line != game->map.width + 1 && game->map.map[i][len_line
			- 1] == '\n')
			return (0);
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_check_borders_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (i == 0 || j == 0 || j == game->map.width - 1
				|| i == game->map.height - 1)
			{
				if (game->map.map[i][j] != '1')
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_validate_path(t_game *game, int item_count, int exit_count)
{
	if (item_count != game->map.collected_item)
	{
		ft_printf("Error: No captureable elements\n");
		return (0);
	}
	if (exit_count != game->map.found_exit)
	{
		ft_printf("Error: Cannot find a valid exit\n");
		return (0);
	}
	return (1);
}

int	ft_is_valid_map(t_game *game, char *file_map)
{
	if (!ft_is_valid_ext(file_map))
	{
		ft_printf("Error: Verify the type of file\n");
		return (0);
	}
	if (!ft_check_map_format(game))
	{
		ft_printf("Error: Invalid map!\n");
		return (0);
	}
	if (!ft_check_borders_map(game))
	{
		ft_printf("Error: The map should be sorrounded by walls\n");
		return (0);
	}
	if (!ft_element_pos(game))
		return (0);
	return (1);
}
