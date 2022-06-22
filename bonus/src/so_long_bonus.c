/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:48:03 by bperron           #+#    #+#             */
/*   Updated: 2022/06/22 15:03:54 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	destroy_image2(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 3)
		mlx_destroy_image(vars->mlx, vars->plane->down[i]);
	i = -1;
	while (++i < 3)
		mlx_destroy_image(vars->mlx, vars->plane->up[i]);
	i = -1;
	while (++i < 3)
		mlx_destroy_image(vars->mlx, vars->plane->right[i]);
	i = -1;
	while (++i < 3)
		mlx_destroy_image(vars->mlx, vars->plane->left[i]);
}

void	destroy_image(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(vars->mlx, vars->airstrip[i]);
	i = -1;
	while (++i < 5)
		mlx_destroy_image(vars->mlx, vars->clouds[i]);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(vars->mlx, vars->enemy[i]);
	i = -1;
	while (++i < 3)
		mlx_destroy_image(vars->mlx, vars->seagull[i]);
	destroy_image2(vars);
}

int	out(t_vars *vars, int code)
{
	int	i;

	i = -1;
	if (vars->map->map)
		while (++i < vars->map->y)
			free(vars->map->map[i]);
	destroy_image(vars);
	free(vars->plane);
	if (code == 0)
		mlx_destroy_window(vars->mlx, vars->win);
	exit (code);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac != 2)
	{
		printf("Error\nIncorrect number of argument\n");
		exit (1);
	}
	init(&vars);
	read_map(&vars, av[1]);
	vars.win = mlx_new_window
		(vars.mlx, vars.map->x * 64, vars.map->y * 64, "so_long");
	create_map(&vars);
	mlx_hook(vars.win, 2, 1L << 0, redirect_key, &vars);
	mlx_hook(vars.win, 17, 0L, out, &vars);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_loop(vars.mlx);
}
