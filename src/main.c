/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:35:01 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/13 23:07:54 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error: %s <map_file>\n", argv[0]);
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_printf("Error allocating memory\n");
		return (1);
	}
	if (!ft_init_vars(game))
	{
		ft_printf("Error: Init variables\n");
		ft_end_game(game);
	}
	ft_start_game(game, argv[1]);

	return (0);
}
