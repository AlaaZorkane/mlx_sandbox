/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 14:18:36 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/24 14:51:10 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_rays *ray, int id)
{
	int	y;
	
	y = -1;
	while (++y < ray->projection.wall_top)
		store.img.matrix[y][id] = 0x8EA4D2;
}

void	draw_content(t_rays *ray, int id)
{
	int y;

	y = ray->projection.wall_top;
	while (++y < ray->projection.wall_bottom)
	{
		store.img.matrix[y][id] = 0xFFFFFF;
	}
}
void	draw_floor(t_rays *ray, int id)
{
	int	y;

	y = ray->projection.wall_bottom;
	while (++y < store.img.height)
		store.img.matrix[y][id] = 0x2EC4B6;
}

