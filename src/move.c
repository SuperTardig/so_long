/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:58:42 by bperron           #+#    #+#             */
/*   Updated: 2022/06/22 15:17:25 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	up(t_vars *vars, int i, int j)
{
	if (vars->map->map[i - 1][j] == 'B')
	{
		printf("You have died. Git gud fuckin noob\n");
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
			printf("Moves : %d\n", vars->move);
		}
		else if (vars->map->items == 0)
		{
			printf("Moves : %d\nNice job!\n", ++vars->move);
			out(vars, 0);
		}
		else
			printf("You still have %d seagull(s) to hit!\n", vars->map->items);
	}
}

void	down(t_vars *vars, int i, int j)
{
	if (vars->map->map[i + 1][j] == 'B')
	{
		printf("You have died. Git gud fuckin noob\n");
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
			printf("Moves : %d\n", vars->move);
		}
		else if (vars->map->items == 0)
		{
			printf("Moves : %d\nNice job!\n", ++vars->move);
			out(vars, 0);
		}
		else
			printf("You still have %d seagull(s) to hit!\n", vars->map->items);
	}
}

void	right(t_vars *vars, int i, int j)
{
	if (vars->map->map[i][j + 1] == 'B')
	{
		printf("You have died. Git gud fuckin noob\n");
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
			printf("Moves : %d\n", vars->move);
		}
		else if (vars->map->items == 0)
		{
			printf("Moves : %d\nNice job!\n", ++vars->move);
			out(vars, 0);
		}
		else
			printf("You still have %d seagull(s) to hit!\n", vars->map->items);
	}
}

void	left(t_vars *vars, int i, int j)
{
	if (vars->map->map[i][j - 1] == 'B')
	{
		printf("You have died. Git gud fuckin noob\n");
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
			printf("Moves : %d\n", vars->move);
		}
		else if (vars->map->items == 0)
		{
			printf("Moves : %d\nNice job!\n", ++vars->move);
			out(vars, 0);
		}
		else
			printf("You still have %d seagull(s) to hit!\n", vars->map->items);
	}
}
