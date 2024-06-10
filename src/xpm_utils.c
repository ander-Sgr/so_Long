/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:06:00 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/10 17:25:01 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	**ft_storage_images(t_game *game, int img_count)
{
	t_img	**images;

	images = (t_img **)malloc(img_count * sizeof(t_img *));
	if (!images)
		return (NULL);
	images[0] = &game->wall;
	images[1] = &game->floor;
	images[2] = &game->character;
	images[3] = &game->item;
	images[4] = &game->exit;
	return (images);
}

static void	ft_clean_xpm(t_game *game, t_img **images, int img_count)
{
	int	i;

	i = 0;
	while (i < img_count)
	{
		if (images[i]->img_ptr)
		{
			mlx_destroy_image(game->mlx.mlx_ptr, images[i]->img_ptr);
			images[i]->img_ptr = NULL;
		}
		i++;
	}
	if (game->mlx.win_ptr)
	{
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
		game->mlx.win_ptr = NULL;
	}
	if (game->mlx.mlx_ptr)
	{
		free(game->mlx.mlx_ptr);
		game->mlx.win_ptr = NULL;
	}
}

static int	ft_check_errors_xpm(t_game *game)
{
	int		img_count;
	int		err_count;
	int		i;
	t_img	**images;

	img_count = 5;
	err_count = 0;
	images = ft_storage_images(game, img_count);
	if (!images)
		return (0);
	while (i < img_count)
	{
		if (!images[i]->img_ptr)
			err_count++;
		i++;
	}
	if (err_count > 0)
	{
		ft_clean_xpm(game, images, img_count);
		printf("Could not load all xpm files\n");
		free(images);
		return (0);
	}
	free(images);
	return (1);
}
static int	ft_load_xpm(t_game *game, t_img *img, char *file_path)
{
	img->img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr, file_path,
			&img->width, &img->heigth);
	if (!img->img_ptr)
	{
		ft_check_errors_xpm(game);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	img->tile_size = TILE_SIZE;
	img->img_path = file_path;
	return (1);
}
t_game	*ft_init_images(t_game *game)
{
	if (!ft_load_xpm(game, &game->wall, "./textures/wall.xpm") ||
		!ft_load_xpm(game, &game->floor, "./textures/floor.xpm") ||
		!ft_load_xpm(game, &game->character, "./textures/character.xpm") ||
		!ft_load_xpm(game, &game->item, "./textures/item.xpm") ||
		!ft_load_xpm(game, &game->exit, "./textures/exit.xpm") ||
		!ft_load_xpm(game, &game->closed_door, "./textures/closed_door.xpm"))
		return (0);

	return (game);
}