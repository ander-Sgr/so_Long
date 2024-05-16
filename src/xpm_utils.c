/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:06:00 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/17 01:14:46 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	*ft_load_xpm(t_game *game, t_img *img, char *file_path)
{
	img->img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr, file_path,
			&img->width, &img->heigth);
	if (!img->img_ptr)
		return (0);
	img->addr = mlx_get_data_addr(img->img_ptr, img->bits_per_pixel,
			img->size_line, img->endian);
	return (1);
}

static void	ft_check_errors_xpm(t_game *game)
{
	int		img_count;
	t_img	*images;

	images = malloc(img_count * sizeof(t_img));
}

t_game	*ft_load_all_xpm(t_game *game)
{
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
