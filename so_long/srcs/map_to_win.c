/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:47:15 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/24 14:30:02 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_to_win(t_game *game, int i, int j)
{
	void	*mlx;
	void	*win;

	mlx = game->mlx;
	win = game->win;
	mlx_put_image_to_window(mlx, win, game->tile.img, j * 64, i * 64);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(mlx, win, game->tree.img, j * 64, i * 64);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(mlx, win, game->collect.img, \
								j * 64 + 12, i * 64 + 12);
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(mlx, win, game->player.img, j * 64, i * 64);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(mlx, win, game->exit.img, j * 64 + 12, i * 64);
}

void	map_to_win(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->y_len)
	{
		j = 0;
		while (j < game->x_len)
		{
			put_img_to_win(game, i, j);
			j++;
		}
		i++;
	}
}
