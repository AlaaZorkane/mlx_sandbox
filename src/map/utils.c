/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 11:26:59 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/23 11:58:42 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_dimensions()
{
	int	index;
	char **map;

	map = store.map.grid;
	index = 0;
	while (map[0][index] == '1')
		index++;
	store.map.cols = index;
	index = 0;
	while (map[index][0] == '1')
		index++;
	store.map.rows = index;
}


int		has_wall_at(int x, int y)
{
	int	grid_x;
	int	grid_y;

	grid_x = floorf((float)x / TILE);
	grid_y = floorf((float)y / TILE);
	return (store.map.grid[grid_y][grid_x] == '1');
}
