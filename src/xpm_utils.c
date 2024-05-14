/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:06:00 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/14 17:07:22 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *ft_load_xpm(t_mlx *mlx, char *file_name, int *width, int *height) {
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

	width = 0;
	height = 0;
	img_ptr = ft_load_xpm(mlx, file_name, &width, &height);
	if (!img_ptr)
	{
		printf("Error al cargar la imagen XPM\n");
		return ;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img_ptr, pos_x * TILE_SIZE, pos_y * TILE_SIZE);
}
