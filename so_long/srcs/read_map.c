/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:31:23 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/24 20:08:36 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_game *game, int fd)
{
	char	c;
	int		temp_x_len;

	temp_x_len = 0;
	while (read(fd, &c, 1) != 0)
	{
		if (game->x_len < temp_x_len)
			game->x_len = temp_x_len;
		if (c == '\n')
		{
			game->y_len++;
			temp_x_len = 0;
		}
		else
			temp_x_len++;
	}
	if (c != '\n')
	game->y_len++;
}

void	alloc_map(t_game *game)
{
	int	i;

	i = 0;
	game->map = (char **)ft_calloc(game->y_len, sizeof(char *));
	if (game->map == NULL)
		exit_err("Malloc fail.\n");
	while (i < game->y_len)
	{
		game->map[i] = (char *)ft_calloc(game->x_len + 1, sizeof(char));
		if (game->map[i] == NULL)
			exit_err("Malloc fail.\n");
		i++;
	}
}

void	parse_map(t_game *game, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		j = -1;
		if (game->x_len != (int)ft_strlen(line))
			exit_free("Map is not rectangle.\n", game->map, game->y_len);
		while (++j < game->x_len)
		{
			check_map_elements(game, line[j]);
			game->map[i][j] = line[j];
			player_location(game, j, i);
		}
		game->map[i][j] = '\0';
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	read_map(t_game *game, char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_err("Open Fail.\n");
	map_size(game, fd);
	close(fd);
	if (game->x_len > 128)
		exit_err("The map is too long.\n");
	alloc_map(game);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_free("Open Fail.\n", game->map, game->y_len);
	parse_map(game, fd);
	close(fd);
	check_cnt(game);
	check_wall(game);
	check_valid(game);
}
