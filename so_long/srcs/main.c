/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:06:58 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/21 22:07:01 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_arg(argc, argv[1]);
	init_game(&game);
	read_map(&game, argv[1]);
	init_mlx(&game);
	map_to_win(&game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
}
