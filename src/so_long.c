/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:48:03 by bperron           #+#    #+#             */
/*   Updated: 2022/06/15 15:34:05 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	plane_move(t_vars *vars)
{
	int	i;
	int	j;
	int stop;

	i = -1;
	stop = 1;
	while (++i < vars->map->y && stop != 0)
	{
		j = 0;
		while (vars->map->map[i][j])
		{
			if (vars->map->map[i][j] == 'P')
			{
				stop = 0;
				break ;
			}
			j++;
		}
	}
	i--;
	if (vars->plane->dir == 0)
	{
		if (vars->map->map[i][j - 1] != '1')
		{
			if (vars->map->map[i][j - 1] != 'E')
			{
				if (vars->map->map[i][j - 1] == 'C')
					vars->map->items--;
				vars->map->map[i][j - 1] = 'P';
				vars->map->map[i][j] = '0';
				vars->move++;
			}
			else if (vars->map->items == 0)
			{
				mlx_destroy_window(vars->mlx, vars->win);
				exit (0);
			}
		}
	}
	if (vars->plane->dir == 1)
	{
		if (vars->map->map[i + 1][j] != '1')
		{
			if (vars->map->map[i + 1][j] != 'E')
			{
				if (vars->map->map[i + 1][j] == 'C')
					vars->map->items--;
				vars->map->map[i + 1][j] = 'P';
				vars->map->map[i][j] = '0';
				vars->move++;
			}
			else if (vars->map->items == 0)
			{
				mlx_destroy_window(vars->mlx, vars->win);
				exit (0);
			}
		}
	}
	if (vars->plane->dir == 2)
	{
		if (vars->map->map[i][j + 1] != '1')
		{
			if (vars->map->map[i][j + 1] != 'E')
			{
				if (vars->map->map[i][j + 1] == 'C')
					vars->map->items--;
				vars->map->map[i][j + 1] = 'P';
				vars->map->map[i][j] = '0';
				vars->move++;
			}
			else if (vars->map->items == 0)
			{
				mlx_destroy_window(vars->mlx, vars->win);
				exit (0);
			}
		}
	}
	if (vars->plane->dir == 13)
	{
		if (vars->map->map[i - 1][j] != '1')
		{
			if (vars->map->map[i - 1][j] != 'E')
			{
				if (vars->map->map[i - 1][j] == 'C')
					vars->map->items--;
				vars->map->map[i - 1][j] = 'P';
				vars->map->map[i][j] = '0';
				vars->move++;
			}
			else if (vars->map->items == 0)
			{
				mlx_destroy_window(vars->mlx, vars->win);
				exit (0);
			}
		}
	}
	create_map(vars);
}

int	redirect_key(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
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

int	out(t_vars *vars)
{
	free(vars->plane);
	exit (0);
}

void	border_map(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->map->map[0][++i])
	{
		if (vars->map->map[0][i] != '1' ||
			vars->map->map[vars->map->y - 1][i] != '1')
		{
			printf("Error\nThe map border must be an obstacle\n");
			exit (1);
		}
	}
	i = -1;
	while (++i < vars->map->y)
	{
		if (vars->map->map[i][0] != '1' ||
			vars->map->map[i][vars->map->x - 1] != '1')
		{
			printf("Error\nThe map border must be an obstacle\n");
			exit (1);
		}
	}
}

void	error_map(t_vars *vars)
{
	if (vars->map->items < 1 || vars->map->exit < 1 || vars->map->start < 1)
	{
		printf("Error\nA mandatory map component is missing\n");
		exit (1);
	}
	if (vars->map->exit > 1 || vars->map->start > 1)
	{
		printf("Error\nToo many exit or starting position\n");
		exit (1);
	}
	if (vars->map->x == vars->map->y)
	{
		printf("Error\nThe map must be a rectangle\n");
		exit (1);
	}
	border_map(vars);
}

void	check_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->map->items = 0;
	vars->map->start = 0;
	vars->map->exit = 0;
	while (i < vars->map->y)
	{
		j = 0;
		while (vars->map->map[i][j] != '\0')
		{
			if (vars->map->map[i][j] == 'C')
			{
				vars->map->items++;
				j++;
			}
			else if (vars->map->map[i][j] == 'P')
			{
				vars->map->start++;
				j++;
			}
			else if (vars->map->map[i][j] == 'E')
			{
				vars->map->exit++;
				j++;
			}
			else if (vars->map->map[i][j] == '1' || vars->map->map[i][j] == '0')
				j++;
			else
			{
				printf("Error\n");
				printf("unerecognized character in map\n");
				exit (1);
			}
		}
		i++;
	}
	error_map(vars);
}

void	get_map_size(t_vars *vars, char *path)
{
	int	fd;

	vars->map->y = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd) != NULL)
		vars->map->y++;
	close (fd);
}

void	read_map(t_vars *vars, char *path)
{
	int	i;
	int	fd;

	i = 0;
	get_map_size(vars, path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nThe file doesn't exist\n");
		exit (1);
	}
	vars->map->map = ft_calloc(vars->map->y, sizeof(char *));
	while (1)
	{
		vars->map->map[i] = get_next_line(fd);
		if (vars->map->map[i] == NULL)
			break ;
		i++;
	}
	close (fd);
	i = 0;
	while (vars->map->map[0][i])
		i++;
	vars->map->x = i;
	check_map(vars);
}

void	create_map(t_vars *vars)
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	*str;

	y = 0;
	i = -1;
	while (++i < vars->map->y)
	{
		x = 0;
		j = -1;
		while (vars->map->map[i][++j])
		{
			if (vars->map->map[i][j] == '1')
				mlx_put_image_to_window
				(vars->map, vars->win, vars->clouds, x, y);
			else if (vars->map->map[i][j] == '0')
				mlx_put_image_to_window
				(vars->map, vars->win, vars->ground, x, y);
			else if (vars->map->map[i][j] == 'P')
				mlx_put_image_to_window
				(vars->map, vars->win, vars->plane->img1, x, y);
			else if (vars->map->map[i][j] == 'E')
				mlx_put_image_to_window
				(vars->map, vars->win, vars->airstrip, x, y);
		//	else if (vars->map->map[i][j] == 'C')	doesnt exist
		//		mlx_put_image_to_window
		//		(vars->map, vars->win, vars->clouds, x, y);
			x += 64;
		}
		y += 64;
	}
	str = ft_itoa(vars->move);
	mlx_string_put(vars->mlx, vars->win, 100, 50, 0x00000000, "moves : ");
	mlx_string_put(vars->mlx, vars->win, 180, 50, 0x00000000, str);
}

int	main(int ac, char *av[])
{
	t_vars	vars;
	int width = 0, height = 0;

	if (ac != 2)
	{
		printf("Error\nIncorrect number of argument\n");
		exit (1);
	}
	vars.move = 0;
	vars.map = malloc(sizeof(t_map));
	vars.plane = malloc(sizeof(t_plane));
	vars.mlx = mlx_init();
	read_map(&vars, av[1]);
	vars.win = mlx_new_window
		(vars.mlx, vars.map->x * 64, vars.map->y * 64, "so_long");
	vars.ground = mlx_xpm_file_to_image
		(vars.mlx, "./asset/grass.xpm", &width, &height);
	vars.plane->img1 = mlx_xpm_file_to_image
		(vars.mlx, "./asset/plane_frame1.xpm", &width, &height);
	vars.clouds = mlx_xpm_file_to_image
		(vars.mlx, "./asset/clouds_frame1.xpm", &width, &height);
	vars.airstrip = mlx_xpm_file_to_image
		(vars.mlx, "./asset/exit_frame1.xpm", &width, &height);
	create_map(&vars);
	mlx_hook(vars.win, 2, 1L << 0, redirect_key, &vars);
	mlx_hook(vars.win, 17, 0L, out, &vars);
	mlx_loop(vars.mlx);
}
