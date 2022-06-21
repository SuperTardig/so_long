/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:48:03 by bperron           #+#    #+#             */
/*   Updated: 2022/06/21 13:28:31 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	out(t_vars *vars, int code)
{
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
