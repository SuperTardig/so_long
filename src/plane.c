/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:28:42 by bperron           #+#    #+#             */
/*   Updated: 2022/06/16 13:59:14 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	redirect_plane(t_vars *vars, int i, int j)
{
	if (vars->plane->dir == 0)
		left(vars, i, j);
	if (vars->plane->dir == 1)
		down(vars, i, j);
	if (vars->plane->dir == 2)
		right(vars, i, j);
	if (vars->plane->dir == 13)
		up(vars, i, j);
}

void	plane_move(t_vars *vars)
{
	int	i;
	int	j;
	int	stop;

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
	redirect_plane(vars, i, j);
	create_map(vars);
}
