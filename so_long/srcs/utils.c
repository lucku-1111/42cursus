/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:48:58 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/24 18:21:05 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_err(char *err_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_msg, 2);
	exit(1);
}

void	player_location(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
	{
		game->player_y = y;
		game->player_x = x;
	}
}

void	exit_free(char *err_msg, char **map, int y_len)
{
	int	i;
	(void) y_len;
	
	i = 0;
	// while (map[i] != NULL)
	while (i < y_len + 1)
		free(map[i++]);
	free(map);
	exit_err(err_msg);
}

void	init_struct_img(t_img *img)
{
	img->img = 0;
	img->width = 0;
	img->height = 0;
}

void	init_game(t_game *game)
{
	game->mlx = 0;
	game->win = 0;
	game->map = 0;
	game->x_len = 0;
	game->y_len = 0;
	game->p_cnt = 0;
	game->c_cnt = 0;
	game->e_cnt = 0;
	game->move_cnt = 0;
	game->player_x = 0;
	game->player_y = 0;
	init_struct_img(&game->collect);
	init_struct_img(&game->exit);
	init_struct_img(&game->player);
	init_struct_img(&game->tile);
	init_struct_img(&game->tree);
}
