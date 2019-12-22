/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 11:20:17 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/22 20:42:35 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H
# include "cub3d.h"

/*
**	Map struct
**	grid: Holds the 2d map schematic (1) WALL, (2) SPRITE, (N/W/E/S)PLAYERSPAWN
**	objects: Holds a record of player/sprites available in the map
**	object_count: How many objects in the map
**	rows/cols: Grid rows/cols
*/

typedef struct s_map
{
	char	**grid;
	char	**objects;
	int		object_count;
	int		rows;
	int		cols;
} t_map;

void	map_setup();
int		has_wall_at(int x, int y);
#endif
