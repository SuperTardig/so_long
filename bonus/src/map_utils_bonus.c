/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:24:00 by bperron           #+#    #+#             */
/*   Updated: 2022/06/23 09:45:51 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	get_map_size(t_vars *vars, char *path)
{
	int		fd;
	char	*hold;

	vars->map->y = 0;
	fd = open(path, O_RDONLY);
	hold = get_next_line(fd);
	while (hold != NULL)
	{
		vars->map->y++;
		free(hold);
		hold = get_next_line(fd);
	}
	free(hold);
	close (fd);
}

void	check_pos(char pos, t_vars *vars)
{
	if (pos == 'C')
		vars->map->items++;
	else if (pos == 'P')
		vars->map->start++;
	else if (pos == 'E')
		vars->map->exit++;
	else if (pos == '0')
		vars->map->ground++;
	else if (pos != '1')
	{
		printf("Error\n");
		printf("unerecognized character in map\n");
		out(vars, 1);
	}
}

void	put_plane(t_vars *vars, int x, int y)
{
	if (vars->plane->dir == 1)
		mlx_put_image_to_window
		(vars->mlx, vars->win, vars->plane->down[vars->frame_plane], x, y);
	else if (vars->plane->dir == 13)
		mlx_put_image_to_window
		(vars->mlx, vars->win, vars->plane->up[vars->frame_plane], x, y);
	else if (vars->plane->dir == 0)
		mlx_put_image_to_window
		(vars->mlx, vars->win, vars->plane->left[vars->frame_plane], x, y);
	else if (vars->plane->dir == 2)
		mlx_put_image_to_window
		(vars->mlx, vars->win, vars->plane->right[vars->frame_plane], x, y);
}

void	put_image(t_vars *vars, int i, int j)
{
	if (vars->map->map[i][j] == '1')
		mlx_put_image_to_window
		(vars->mlx, vars->win,
		vars->clouds[vars->frame_cloud], vars->x, vars->y);
	else if (vars->map->map[i][j] == '0')
		mlx_put_image_to_window
		(vars->mlx, vars->win, vars->ground, vars->x, vars->y);
	else if (vars->map->map[i][j] == 'P')
		put_plane(vars, vars->x, vars->y);
	else if (vars->map->map[i][j] == 'E')
		mlx_put_image_to_window
		(vars->mlx, vars->win,
		vars->airstrip[vars->frame_exit], vars->x, vars->y);
	else if (vars->map->map[i][j] == 'C')
		mlx_put_image_to_window
		(vars->mlx, vars->win,
		vars->seagull[vars->frame_seagull], vars->x, vars->y);
	else if (vars->map->map[i][j] == 'B')
		mlx_put_image_to_window
		(vars->mlx, vars->win,
		vars->enemy[vars->frame_enemy], vars->x, vars->y);
	vars->x += 64;
}

void	put_map_in_var(t_vars *vars, int fd)
{
	int	i;

	i = 0;
	while (1)
	{
		vars->map->map[i] = get_next_line(fd);
		if (vars->map->map[i] == NULL)
			break ;
		i++;
	}
}
