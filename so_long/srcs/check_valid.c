/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:03:27 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/24 14:24:50 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_info(t_game *game, t_valid *info)
{
	int	i;

	i = 0;
	info->count = game->c_cnt;
	info->exit = 0;
	info->visited = (char **)ft_calloc(game->y_len + 1, sizeof(char *));
	if (info->visited == NULL)
		exit_err("Malloc fail.\n");
	while (i < game->y_len)
	{
		info->visited[i] = ft_strdup(game->map[i]);
		if (info->visited[i] == 0)
			exit_err("Malloc fail.\n");
		i++;
	}
	info->visited[i] = 0;
}

void	check_path(t_valid *info, int x, int y)
{
	if (info->visited[y][x] == '1')
		return ;
	else if (info->visited[y][x] == 'C')
		info->count--;
	else if (info->visited[y][x] == 'E')
		info->exit = 1;
	info->visited[y][x] = '1';
	check_path(info, x - 1, y);
	check_path(info, x + 1, y);
	check_path(info, x, y - 1);
	check_path(info, x, y + 1);
}

void	check_valid(t_game *game)
{
	t_valid	info;
	int		i;

	i = 0;
	init_info(game, &info);
	check_path(&info, game->player_x, game->player_y);
	if (info.count != 0 || info.exit == 0)
	{
		while (i < game->y_len + 1)
			free(info.visited[i++]);
		free(info.visited);
		exit_free("The map needs a valid path.\n", game->map, game->y_len);
	}
	else
	{
		while (i < game->y_len + 1)
			free(info.visited[i++]);
		free(info.visited);
	}
}
