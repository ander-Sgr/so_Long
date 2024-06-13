/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:53:10 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/13 23:03:43 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
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

# define K_A 97
# define K_S 115
# define K_D 100
# define K_W 119

# define K_ESC 65307

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			character_count;
	int			exit_count;
	int			item_count;
	int			found_exit;
	int			collected_item;
	t_pos		exit_pos;
}				t_map;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct s_player
{
	t_pos		pos_player;
	int			items_recollected;
	int			mov_count;
	char		current_tile;
}				t_player;

typedef struct s_img
{
	void		*img_ptr;
	char		*img_path;
	char		*addr;
	int			width;
	int			heigth;
	int			tile_size;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_game
{
	t_mlx		mlx;
	t_player	player;
	t_map		map;
	t_pos		pos;
	t_img		wall;
	t_img		floor;
	t_img		character;
	t_img		item;
	t_img		exit;
	t_img		closed_door;
}				t_game;

t_game			*ft_init_map(char *file_map, t_game *game);
int				ft_draw_map(t_game *game);
t_game			*ft_init_images(t_game *game);
int				ft_is_valid_map(t_game *game, char *file_map);
int				ft_check_pathfinder(t_game *game, t_pos *start_pos);
t_game			*ft_element_pos(t_game *game);
int				ft_check_elements_map(t_game *game);
void			ft_draw_elements(t_game *game, int x, int y);
void			ft_update_player_position(t_game *game, int new_x, int new_y);
void			ft_cleanup_map(t_game *game);
int				ft_validate_path(t_game *game, int item_count, int exit_count);
int				ft_end_game(t_game *game);
void			ft_mlx_closing(t_game *game);
void			ft_start_game(t_game *game, char *file_map);

int				ft_init_wall(t_game *game);
int				ft_init_floor(t_game *game);
int				ft_init_character(t_game *game);
int				ft_init_item(t_game *game);
int				ft_init_exit(t_game *game);

int				ft_init_vars(t_game *game);

int				handle_keypress(int keysym, t_game *data);

#endif
