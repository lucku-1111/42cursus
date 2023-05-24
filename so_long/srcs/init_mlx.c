/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:49:43 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/24 16:09:15 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(void *mlx, char *file, t_img *img_name)
{
	int	w;
	int	h;

	img_name->img = mlx_xpm_file_to_image(mlx, file, &w, &h);
	if (img_name->img == NULL)
		exit_err("Image load fail.\n");
	img_name->width = w;
	img_name->height = h;
}

void	init_img(t_game *game)
{
	load_img(game->mlx, "./images/collect.xpm", &game->collect);
	load_img(game->mlx, "./images/exit.xpm", &game->exit);
	load_img(game->mlx, "./images/player.xpm", &game->player);
	load_img(game->mlx, "./images/tile.xpm", &game->tile);
	load_img(game->mlx, "./images/tree.xpm", &game->tree);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit_err("Mlx init fail.\n");
	game->win = mlx_new_window(game->mlx, \
				game->x_len * 64, game->y_len * 64, "so_long");
	if (game->win == NULL)
		exit_err("New window fail.\n");
	init_img(game);
}
