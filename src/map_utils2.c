/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:53:53 by bperron           #+#    #+#             */
/*   Updated: 2022/06/22 14:07:14 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	rectangle_map(t_vars *vars)
{
	int	i;

	i = -1;
	if (vars->map->x == vars->map->y)
	{
		printf("Error\nThe map must be a rectangle\n");
		out(vars, 1);
	}
	while (++i < vars->map->y)
	{
		if (ft_strlen(vars->map->map[i]) != (size_t) vars->map->x)
		{
			printf("Error\nThe map must be a rectangle\n");
			out(vars, 1);
		}
	}
}

void	print_strings(t_vars *vars)
{
	char	*str;
	char	*item;
	char	*counter;

	str = ft_itoa(vars->move);
	item = ft_itoa(vars->map->items);
	counter = ft_itoa(vars->map->counter);
	mlx_string_put(vars->mlx, vars->win, 50, 20, 0x00000000, "moves : ");
	mlx_string_put(vars->mlx, vars->win, 130, 20, 0x00000000, str);
	mlx_string_put(vars->mlx, vars->win, 200, 20, 0x00000000,
		"Seagulls left : ");
	mlx_string_put(vars->mlx, vars->win, 350, 20, 0x00000000, item);
	mlx_string_put(vars->mlx, vars->win, 360, 20, 0x00000000, " / ");
	mlx_string_put(vars->mlx, vars->win, 390, 20, 0x00000000, counter);
	free(str);
	free(item);
	free(counter);
}

void	place_enemy(t_vars *vars)
{
	int	i;
	int	j;
	int	stop;

	i = -1;
	stop = 0;
	while (++i < vars->map->y && stop == 0)
	{
		j = -1;
		while (vars->map->map[i][++j])
		{
			if (vars->map->map[i][j] == '0')
				vars->map->place--;
			if (vars->map->place == 0)
			{
				vars->map->map[i][j] = 'B';
				stop = 1;
				break ;
			}
		}
	}
}
