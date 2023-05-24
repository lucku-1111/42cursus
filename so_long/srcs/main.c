/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:06:58 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/24 18:08:47 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void runleaks(void)
// {
// 	system("leaks -q so_long");
// }

int	main(int argc, char **argv)
{
	t_game	game;

	// atexit(runleaks);
	check_arg(argc, argv[1]);
	init_game(&game);
	read_map(&game, argv[1]);
	init_mlx(&game);
	map_to_win(&game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
}
