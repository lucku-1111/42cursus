/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:47:08 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/24 20:00:06 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_window(game->mlx, game->win);
	while (i < game->y_len)
		free(game->map[i++]);
	free(game->map);
	exit(0);
}

void	check_gameover(t_game *game)
{
	if (game->c_cnt == 0 && game->e_cnt == 0)
	{
		ft_putstr_fd("You moved ", 1);
		ft_putnbr_fd(game->move_cnt, 1);
		ft_putstr_fd(" times.\n", 1);
		close_game(game);
	}
}

void	print_move_cnt(int num)
{
	ft_putnbr_fd(num, 1);
	ft_putstr_fd("\n", 1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		close_game(game);
	else if (keycode == 13)
		move_up(game);
	else if (keycode == 1)
		move_down(game);
	else if (keycode == 0)
		move_left(game);
	else if (keycode == 2)
		move_right(game);
	check_gameover(game);
	map_to_win(game);
	return (1);
}
