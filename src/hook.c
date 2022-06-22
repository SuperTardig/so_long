/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:39:43 by bperron           #+#    #+#             */
/*   Updated: 2022/06/22 11:16:01 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	anim(t_vars *vars)
{
	vars->frame_seagull++;
	if (vars->frame_seagull == 3)
		vars->frame_seagull = 0;
	vars->frame_exit++;
	if (vars->frame_exit == 4)
		vars->frame_exit = 0;
	vars->frame_enemy++;
	if (vars->frame_enemy == 4)
		vars->frame_enemy = 0;
	create_map(vars);
}

int	loop_hook(t_vars *vars)
{
	if (vars->frame % 750 == 0)
	{
		vars->frame_plane++;
		if (vars->frame_plane == 3)
			vars->frame_plane = 0;
		create_map(vars);
	}
	if (vars->frame % 1000 == 0)
		anim(vars);
	if (vars->frame % 5000 == 0)
	{
		vars->frame_cloud++;
		if (vars->frame_cloud == 5)
			vars->frame_cloud = 0;
		enemy(vars);
		vars->frame = 0;
		create_map(vars);
	}
	vars->frame++;
	return (0);
}

int	redirect_key(int keycode, t_vars *vars)
{
	if (keycode == 53)
		out(vars, 0);
	else if ((keycode >= 0 && keycode <= 2) || keycode == 13)
	{
		vars->plane->dir = keycode;
		if (keycode == 0)
			plane_move(vars);
		if (keycode == 1)
			plane_move(vars);
		if (keycode == 2)
			plane_move(vars);
		if (keycode == 13)
			plane_move(vars);
	}
	return (0);
}
