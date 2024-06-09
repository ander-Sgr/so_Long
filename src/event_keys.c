/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:58:37 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/10 00:57:07 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_game *data)
{
    if (keysym == K_ESC)
        mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);

    printf("Keypress: %d\n", keysym);
    return (0);
}