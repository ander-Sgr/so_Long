/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:53:10 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/12 20:55:03 by aestrell         ###   ########.fr       */
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
#  define WIN_HEIGHT 500
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 900
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 80
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
	int width;  // height
	int height; // width
}			t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;

}			t_mlx;

typedef struct s_square
{
	t_pos	pos;
	int		size;
	int		color;

}			t_square;

void		init_map(char *file_map, t_map *map);
void		draw_xpm(t_mlx *mlx, char *file_name, int pos_x, int pos_y);
void		draw_map(t_mlx *mlx, t_map *map);

#endif
