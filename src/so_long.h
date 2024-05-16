/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:53:10 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/16 22:48:12 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 400
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 600
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

// map stuct
typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width_win;
	int		height_win;
}			t_mlx;

typedef struct s_player
{
	t_pos	pos_player;
	int		items_recollected;
	int		mov_count;
}			t_player;

typedef	struct s_img
{
	t_mlx	mlx;
	t_pos	pos_img;
	int		tile_size;
	char	*img_path;
	char	*addr;
	int		pixels;
	int		endian;
}			t_img;


typedef struct s_game
{
	t_mlx		mlx;
	t_player	player;
	t_map		map;
	t_img		wall;
	t_img		floor;
	t_img		character;
}			t_game;

void	init_map(char *file_map, t_map *map);
void	draw_xpm(t_mlx *mlx, char *file_name, int pos_x, int pos_y);
void	draw_map(t_mlx *mlx, t_map *map);

#endif
