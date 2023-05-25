/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:13:23 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/24 20:03:39 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct s_valid{
	char	**visited;
	int		count;
	int		exit;
}	t_valid;

typedef struct s_img{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_game{
	void	*mlx;
	void	*win;
	char	**map;
	int		x_len;
	int		y_len;
	int		p_cnt;
	int		c_cnt;
	int		e_cnt;
	int		move_cnt;
	int		player_x;
	int		player_y;
	t_img	collect;
	t_img	exit;
	t_img	player;
	t_img	tile;
	t_img	tree;
}	t_game;

void	check_arg(int argc, char *map_file);
void	exit_err(char *err_msg);
void	init_game(t_game *game);
void	init_struct_img(t_img *img);
void	read_map(t_game *game, char *map_file);
void	map_size(t_game *game, int fd);
void	alloc_map(t_game *game);
void	exit_free(char *err_msg, char **map, int y_len);
void	parse_map(t_game *game, int fd);
void	player_location(t_game *game, int x, int y);
void	check_cnt(t_game *game);
void	check_map_elements(t_game *game, char c);
void	check_wall(t_game *game);
void	check_valid(t_game *game);
void	init_info(t_game *game, t_valid *info);
void	check_path(t_valid *info, int x, int y);
void	init_mlx(t_game *game);
void	init_img(t_game *game);
void	load_img(t_game *game, char *file, t_img *img_name);
void	map_to_win(t_game *game);
void	put_img_to_win(t_game *game, int i, int j);
int		key_hook(int keycode, t_game *game);
void	check_gameover(t_game *game);
int		close_game(t_game *game);
void	print_move_cnt(int num);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

#endif