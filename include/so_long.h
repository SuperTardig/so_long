/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:41:14 by bperron           #+#    #+#             */
/*   Updated: 2022/06/22 15:23:31 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "../libft/libft.h"

typedef struct s_plane{
	void	*up[3];
	void	*down[3];
	void	*right[3];
	void	*left[3];
	int		dir;
}	t_plane;

typedef struct s_map{
	int		x;
	int		y;
	int		items;
	int		counter;
	int		exit;
	int		start;
	int		ground;
	int		place;
	char	**map;
}	t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*clouds[5];
	void	*airstrip[4];
	void	*seagull[3];
	void	*enemy[4];
	void	*ground;
	t_plane	*plane;
	t_map	*map;
	int		move;
	int		frame;
	int		frame_seagull;
	int		frame_plane;
	int		frame_exit;
	int		frame_cloud;
	int		frame_enemy;
	int		x;
	int		y;
}	t_vars;

void	init(t_vars *vars);
void	init_image(t_vars *vars);
void	init_image2(t_vars *vars);
void	init_image3(t_vars *vars);

void	read_map(t_vars *vars, char *path);
void	get_map_size(t_vars *vars, char *path);
void	check_pos(char pos, t_vars *vars);
void	check_map(t_vars *vars);
void	error_map(t_vars *vars);
void	border_map(t_vars *vars);
void	put_map_in_var(t_vars *vars, int fd);
void	rectangle_map(t_vars *vars);
void	print_strings(t_vars *vars);
void	place_enemy(t_vars *vars);

void	redirect_plane(t_vars *vars, int i, int j);
void	plane_move(t_vars *vars);
void	up(t_vars *vars, int i, int j);
void	down(t_vars *vars, int i, int j);
void	right(t_vars *vars, int i, int j);
void	left(t_vars *vars, int i, int j);

void	create_map(t_vars *vars);
void	put_image(t_vars *vars, int x, int y);
void	put_plane(t_vars *vars, int x, int y);

void	anim(t_vars *vars);
int		loop_hook(t_vars *vars);
int		redirect_key(int keycode, t_vars *vars);

void	enemy(t_vars *vars);
void	left_enemy(t_vars *vars, int i, int j);
void	right_enemy(t_vars *vars, int i, int j);
void	down_enemy(t_vars *vars, int i, int j);
void	up_enemy(t_vars *vars, int i, int j);
void	redirect_enemy(t_vars *vars, int dir, int i, int j);

int		out(t_vars *vars, int code);
void	destroy_image(t_vars *vars);

#endif
