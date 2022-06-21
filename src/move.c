/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:58:42 by bperron           #+#    #+#             */
/*   Updated: 2022/06/21 15:01:40 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	up(t_vars *vars, int i, int j)
{
	if (vars->map->map[i - 1][j] == 'B')
	{
		printf("You have died...\n");
		out(vars, 0);
	}
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
			printf("Nice job!\n");
			out(vars, 0);
		}
		else
			printf("You still have some seagulls to hit!\n");
	}
}

void	down(t_vars *vars, int i, int j)
{
	if (vars->map->map[i + 1][j] == 'B')
	{
		printf("You have died...\n");
		out(vars, 0);
	}
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
			printf("Nice job!\n");
			out(vars, 0);
		}
		else
			printf("You still have some seagulls to hit!\n");
	}
}

void	right(t_vars *vars, int i, int j)
{
	if (vars->map->map[i][j + 1] == 'B')
	{
		printf("You have died...\n");
		out(vars, 0);
	}
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
			printf("Nice job!\n");
			out(vars, 0);
		}
		else
			printf("You still have some seagulls to hit!\n");
	}
}

void	left(t_vars *vars, int i, int j)
{
	if (vars->map->map[i][j - 1] == 'B')
	{
		printf("You have died...\n");
		out(vars, 0);
	}
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
			printf("Nice job!\n");
			out(vars, 0);
		}
		else
			printf("You still have some seagulls to hit!\n");
	}
}
