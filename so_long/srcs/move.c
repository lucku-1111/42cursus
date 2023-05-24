/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:24:01 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/21 21:38:49 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
	{
		if (game->map[y - 1][x] == 'C')
			game->c_cnt--;
		game->map[y - 1][x] = 'P';
		game->map[y][x] = '0';
		game->player_y--;
		game->move_cnt++;
		print_move_cnt(game->move_cnt);
	}
	else if (game->map[y - 1][x] == 'E' && game->c_cnt == 0)
	{
		game->e_cnt = 0;
		game->move_cnt++;
	}
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
	{
		if (game->map[y + 1][x] == 'C')
			game->c_cnt--;
		game->map[y + 1][x] = 'P';
		game->map[y][x] = '0';
		game->player_y++;
		game->move_cnt++;
		print_move_cnt(game->move_cnt);
	}
	else if (game->map[y + 1][x] == 'E' && game->c_cnt == 0)
	{
		game->e_cnt = 0;
		game->move_cnt++;
	}
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
	{
		if (game->map[y][x - 1] == 'C')
			game->c_cnt--;
		game->map[y][x - 1] = 'P';
		game->map[y][x] = '0';
		game->player_x--;
		game->move_cnt++;
		print_move_cnt(game->move_cnt);
	}
	else if (game->map[y][x - 1] == 'E' && game->c_cnt == 0)
	{
		game->e_cnt = 0;
		game->move_cnt++;
	}
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
	{
		if (game->map[y][x + 1] == 'C')
			game->c_cnt--;
		game->map[y][x + 1] = 'P';
		game->map[y][x] = '0';
		game->player_x++;
		game->move_cnt++;
		print_move_cnt(game->move_cnt);
	}
	else if (game->map[y][x + 1] == 'E' && game->c_cnt == 0)
	{
		game->e_cnt = 0;
		game->move_cnt++;
	}
}
