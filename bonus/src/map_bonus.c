/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:24:04 by bperron           #+#    #+#             */
/*   Updated: 2022/06/22 15:03:19 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
			out(vars, 1);
		}
	}
	i = -1;
	while (++i < vars->map->y)
	{
		if (vars->map->map[i][0] != '1' ||
			vars->map->map[i][vars->map->x - 1] != '1')
		{
			printf("Error\nThe map border must be an obstacle\n");
			out(vars, 1);
		}
	}
}

void	error_map(t_vars *vars)
{
	if (vars->map->items < 1 || vars->map->exit < 1 || vars->map->start < 1)
	{
		printf("Error\nA mandatory map component is missing\n");
		out(vars, 1);
	}
	if (vars->map->start > 1)
	{
		printf("Error\nToo many Starting positions or enemies\n");
		out(vars, 1);
	}
	rectangle_map(vars);
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
	vars->map->ground = 0;
	while (i < vars->map->y)
	{
		j = 0;
		while (vars->map->map[i][j] != '\0')
		{
			check_pos(vars->map->map[i][j], vars);
			j++;
		}
		i++;
	}
	vars->map->counter = vars->map->items;
	if (vars->map->ground > 25)
	{
		vars->map->place = (rand() % ((vars->map->ground - 1) - 1 + 1)) + 1;
		place_enemy(vars);
	}
	error_map(vars);
}

void	create_map(t_vars *vars)
{
	int		i;
	int		j;

	vars->y = 0;
	i = -1;
	while (++i < vars->map->y)
	{
		vars->x = 0;
		j = -1;
		while (vars->map->map[i][++j])
			put_image(vars, i, j);
		vars->y += 64;
	}
	print_strings(vars);
}

void	read_map(t_vars *vars, char *path)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nThe file doesn't exist\n");
		out(vars, 1);
	}
	if (ft_strnstr(path, ".ber", ft_strlen(path)) == 0)
	{
		printf("Error\nThe file doesn't end in .ber\n");
		out(vars, 1);
	}
	get_map_size(vars, path);
	vars->map->map = ft_calloc(vars->map->y + 1, sizeof(char *));
	put_map_in_var(vars, fd);
	close (fd);
	while (vars->map->map[0][i])
		i++;
	vars->map->x = i;
	check_map(vars);
}
