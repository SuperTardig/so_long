/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:01:13 by bperron           #+#    #+#             */
/*   Updated: 2022/06/26 09:49:36 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_image3(t_vars *vars)
{
	int	height;
	int	width;

	vars->plane->right[1] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/plane_right_frame2.xpm", &width, &height);
	vars->plane->right[2] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/plane_right_frame3.xpm", &width, &height);
	vars->airstrip[0] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/exit_frame1.xpm", &width, &height);
	vars->airstrip[1] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/exit_frame2.xpm", &width, &height);
	vars->airstrip[2] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/exit_frame3.xpm", &width, &height);
	vars->airstrip[3] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/exit_frame4.xpm", &width, &height);
	vars->seagull[0] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/seagull_frame1.xpm", &width, &height);
	vars->seagull[1] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/seagull_frame2.xpm", &width, &height);
	vars->seagull[2] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/seagull_frame3.xpm", &width, &height);
}

void	init_image2(t_vars *vars)
{
	int	height;
	int	width;

	vars->plane->up[0] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/plane_up_frame1.xpm", &width, &height);
	vars->plane->up[1] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/plane_up_frame2.xpm", &width, &height);
	vars->plane->up[2] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/plane_up_frame3.xpm", &width, &height);
	vars->plane->down[0] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/plane_down_frame1.xpm", &width, &height);
	vars->plane->down[1] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/plane_down_frame2.xpm", &width, &height);
	vars->plane->down[2] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/plane_down_frame3.xpm", &width, &height);
	vars->plane->left[0] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/plane_left_frame1.xpm", &width, &height);
	vars->plane->left[1] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/plane_left_frame2.xpm", &width, &height);
	vars->plane->left[2] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/plane_left_frame3.xpm", &width, &height);
	vars->plane->right[0] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/plane_right_frame1.xpm", &width, &height);
	init_image3(vars);
}

void	init_image(t_vars *vars)
{
	int	height;
	int	width;

	vars->ground = mlx_xpm_file_to_image
		(vars->mlx, "./asset/grass.xpm", &width, &height);
	vars->clouds[0] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/clouds_frame1.xpm", &width, &height);
	vars->clouds[1] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/clouds_frame2.xpm", &width, &height);
	vars->clouds[2] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/clouds_frame3.xpm", &width, &height);
	vars->clouds[3] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/clouds_frame4.xpm", &width, &height);
	vars->clouds[4] = mlx_xpm_file_to_image
		(vars->mlx, "./asset/clouds_frame5.xpm", &width, &height);
	init_image2(vars);
}

void	init(t_vars *vars)
{

	vars->mlx = mlx_init();
	vars->plane = malloc(sizeof(t_plane));
	vars->map = malloc(sizeof(t_map));
	vars->move = 0;
	vars->plane->dir = 1;
	vars->frame = 0;
	vars->frame_seagull = 0;
	vars->frame_exit = 0;
	vars->frame_plane = 0;
	vars->frame_cloud = 0;
	init_image(vars);
}
