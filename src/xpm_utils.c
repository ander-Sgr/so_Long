/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:06:00 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/20 19:55:09 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_load_xpm(t_game *game, t_img *img, char *file_path)
{
	img->img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr, file_path,
			&img->width, &img->heigth);
	if (!img->img_ptr)
	{
		fprintf(stderr, "Error loading XPM file: %s\n", file_path);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	return (1);
}

/* 
static int	ft_check_errors_xpm(t_game *game)
{
	int		img_count;
	int		err_count;
	int		i;
	t_img	*images[2];

	img_count = 2;
	err_count = 0;
	images[0] = &game->wall;
	images[1] = &game->floor;
	i = 0;
	while (i < img_count)
	{
		if (!images[i]->img_ptr)
			err_count++;
		i++;
	}
	if (err_count > 0)
	{
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
			game->mlx.mlx_ptr = NULL;
		}
		return (0);
	}
	return (1);
} */
t_game	*ft_init_images(t_game *game)
{
	if (!ft_load_xpm(game, &game->wall, "./textures/wall.xpm") ||
		!ft_load_xpm(game, &game->floor, "./textures/floor.xpm") ||
		!ft_load_xpm(game, &game->character, "./textures/character.xpm"))
		return (NULL);
	return (game);
}

/*
void	*ft_load_xpm(t_mlx *mlx, char *file_name, int *width, int *height) {
    void *img;

    img = mlx_xpm_file_to_image(mlx->mlx_ptr, file_name, width, height);
    if (img == NULL) {
        printf("Error al cargar la imagen XPM\n");
        return (NULL);
    }
    return (img);
}
void	draw_xpm(t_mlx *mlx, char *file_name, int pos_x, int pos_y)
{
	int		width;
	int		height;
	void	*img_ptr;

	img_ptr = ft_load_xpm(mlx, file_name, &width, &height);
	if (!img_ptr)
	{
		printf("Error al cargar la imagen XPM\n");
		return ;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img_ptr, pos_x
			* TILE_SIZE, pos_y * TILE_SIZE);
}
*/
