/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:02:08 by bperron           #+#    #+#             */
/*   Updated: 2022/06/22 15:17:39 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	up_enemy(t_vars *vars, int i, int j)
{
	if (vars->map->map[i - 1][j] == 'P')
	{
		printf("You have died. Git gud fuckin noob\n");
		out(vars, 0);
	}
	if (vars->map->map[i - 1][j] != '1' &&
	vars->map->map[i - 1][j] != 'E' && vars->map->map[i - 1][j] != 'C')
	{
			vars->map->map[i - 1][j] = 'B';
			vars->map->map[i][j] = '0';
	}
}

void	down_enemy(t_vars *vars, int i, int j)
{
	if (vars->map->map[i + 1][j] == 'P')
	{
		printf("You have died. Git gud fuckin noob\n");
		out(vars, 0);
	}
	if (vars->map->map[i + 1][j] != '1' &&
	vars->map->map[i + 1][j] != 'E' && vars->map->map[i + 1][j] != 'C')
	{
			vars->map->map[i + 1][j] = 'B';
			vars->map->map[i][j] = '0';
	}
}

void	right_enemy(t_vars *vars, int i, int j)
{
	if (vars->map->map[i][j + 1] == 'P')
	{
		printf("You have died. Git gud fuckin noob\n");
		out(vars, 0);
	}
	if (vars->map->map[i][j + 1] != '1' &&
	vars->map->map[i][j + 1] != 'E' && vars->map->map[i][j + 1] != 'C')
	{
			vars->map->map[i][j + 1] = 'B';
			vars->map->map[i][j] = '0';
	}
}

void	left_enemy(t_vars *vars, int i, int j)
{
	if (vars->map->map[i][j - 1] == 'P')
	{
		printf("You have died. Git gud fuckin noob\n");
		out(vars, 0);
	}
	if (vars->map->map[i][j - 1] != '1' &&
	vars->map->map[i][j - 1] != 'E' && vars->map->map[i][j - 1] != 'C')
	{
			vars->map->map[i][j - 1] = 'B';
			vars->map->map[i][j] = '0';
	}
}
