/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:49:43 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/25 17:04:55 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_game *game, char *file, t_img *img_name)
{
	int	w;
	int	h;

	img_name->img = mlx_xpm_file_to_image(game->mlx, file, &w, &h);
	if (img_name->img == NULL)
		exit_free("Image load fail.\n", game->map, game->y_len);
	img_name->width = w;
	img_name->height = h;
}

void	init_img(t_game *game)
{
	load_img(game, "./textures/collect.xpm", &game->collect);
	load_img(game, "./textures/exit.xpm", &game->exit);
	load_img(game, "./textures/player.xpm", &game->player);
	load_img(game, "./textures/tile.xpm", &game->tile);
	load_img(game, "./textures/tree.xpm", &game->tree);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit_free("Mlx init fail.\n", game->map, game->y_len);
	game->win = mlx_new_window(game->mlx, \
				game->x_len * 64, game->y_len * 64, "so_long");
	if (game->win == NULL)
		exit_free("New window fail.\n", game->map, game->y_len);
	init_img(game);
}
