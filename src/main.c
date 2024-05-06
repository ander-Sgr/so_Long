/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:35:01 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/07 00:04:19 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void	draw_square(t_mlx mlx, t_pos pos, t_square square)
{
	int	i;
	int	j;

	i = 0;
	while (i < square.size)
	{
		j = 0;
		while (j < square.size)
		{
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, pos.x + i, pos.y + j,
					square.color);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_mlx mlx;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 500, 500, "test window");
	t_pos pos = {100, 100};
	t_square square = {pos, 50, 0xFFFFFF};

	draw_square(mlx, pos, square);

	mlx_loop(mlx.mlx_ptr);
	return (0);
}