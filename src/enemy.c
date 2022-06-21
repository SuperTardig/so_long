/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:48:25 by bperron           #+#    #+#             */
/*   Updated: 2022/06/21 15:05:25 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	redirect_enemy(t_vars *vars, int dir, int i, int j)
{
	if (dir == 1)
		left_enemy(vars, i, j);
	else if (dir == 2)
		down_enemy(vars, i, j);
	else if (dir == 3)
		right_enemy(vars, i, j);
	else if (dir == 4)
		up_enemy(vars, i, j);
}

void	enemy(t_vars *vars)
{
	int	dir;
	int	i;
	int	j;
	int	stop;

	i = -1;
	stop = 0;
	dir = (rand() % (4 - 1 + 1)) + 1;
	while (++i < vars->map->y && stop == 0)
	{
		j = 0;
		while (vars->map->map[i][j])
		{
			if (vars->map->map[i][j] == 'B')
			{
				redirect_enemy(vars, dir, i, j);
				stop = 1;
				break ;
			}
			j++;
		}
	}
}
