/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:53:10 by aestrell          #+#    #+#             */
/*   Updated: 2024/05/07 00:49:15 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// map stuct
typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		heigth;
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

#endif