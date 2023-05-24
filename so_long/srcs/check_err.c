/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:41:30 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/24 14:29:42 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(int argc, char *map_file)
{
	if (argc != 2)
		exit_err("Invalid number of arguments.\n");
	if (ft_strlen(map_file) < 4 || ft_strrchr(map_file, '.') == 0)
		exit_err("Invalid argument.\n");
	if (ft_strncmp(ft_strrchr(map_file, '.'), ".ber", 5) != 0)
		exit_err("Invalid extension.\n");
}

void	check_cnt(t_game *game)
{
	if (game->p_cnt != 1)
		exit_free("The map must have one player.\n", game->map, game->y_len);
	if (game->e_cnt != 1)
		exit_free("The map must have one exit.\n", game->map, game->y_len);
	if (game->c_cnt < 1)
		exit_free("The map must have at least one collection. \
					\n", game->map, game->y_len);
}

void	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->y_len)
	{
		if (game->map[i][0] != '1' || game->map[i][game->x_len - 1] != '1')
			exit_free("The map is not surrounded by walls.\n", \
						game->map, game->y_len);
		i++;
	}
	i = 0;
	while (i < game->x_len)
	{
		if (game->map[0][i] != '1' || game->map[game->y_len - 1][i] != '1')
			exit_free("The map is not surrounded by walls.\n", \
						game->map, game->y_len);
		i++;
	}
}

void	check_map_elements(t_game *game, char c)
{
	if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
		exit_free("Invalid map elements.\n", game->map, game->y_len);
	if (c == 'P')
		game->p_cnt++;
	else if (c == 'E')
		game->e_cnt++;
	else if (c == 'C')
		game->c_cnt++;
}
