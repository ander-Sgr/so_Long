/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:35:01 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/12 19:58:09 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx	mlx;
	t_map	map;

	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_HEIGHT, WIN_HEIGHT,
			"so_long");
	if (mlx.win_ptr == NULL)
		return (1);
	init_map("./maps/map1.ber", &map);
	if (map.map == NULL)
		printf("Error read map: \n");
	printf("width map: %d\nheight map: %d\n", map.width, map.height);
	draw_map(&mlx, &map);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
