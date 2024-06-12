/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:35:01 by aestrell          #+#    #+#             */
/*   Updated: 2024/06/13 00:06:46 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		printf("Error: %s <map_file>\n", argv[0]);
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		printf("Error allocating memory\n");
		return (1);
	}
	if (!ft_init_vars(game))
	{
		printf("Error: Init variables\n");
		ft_end_game(game);
	}
	ft_start_game(game, argv[1]);
	ft_end_game(game);
	return (0);
}
