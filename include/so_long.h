/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:41:14 by bperron           #+#    #+#             */
/*   Updated: 2022/06/15 15:01:14 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_plane{
	void	*img1;
	void	*img2;
	void	*img3;
	int		x;
	int		y;
	int		dir;
}	t_plane;

typedef struct s_map{
	int		x;
	int		y;
	int		items;
	int		exit;
	int		start;
	char	**map;
}	t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*clouds;
	void	*airstrip;
	void	*ground;
	t_plane	*plane;
	t_map	*map;
	int		move;
}	t_vars;

void	create_map(t_vars *vars);

#endif
