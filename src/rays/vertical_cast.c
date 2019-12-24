/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_cast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 12:40:25 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/23 12:08:59 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int wall_hit(t_rays *ray)
{
	if (ray->vertical.next_hit_x >= 0)
		if (ray->vertical.next_hit_x <= store.img.width)
			if (ray->vertical.next_hit_y >= 0)
					return (ray->vertical.next_hit_y <= store.img.height);
	return (0);
}

static void	setup_intersects(float angle, t_rays *ray)
{
	ray->intersects.x_intersect = floor(store.player.x / TILE) * TILE;
	ray->intersects.x_intersect += ray->ray_face & RAY_UP ? TILE : 0;
	ray->intersects.y_intersect = store.player.y +
		(ray->intersects.x_intersect - store.player.x) / tan(angle);
}

static void	setup_steps(float angle, t_rays *ray)
{
	ray->intersects.x_step = TILE;
	ray->intersects.x_step *= ray->ray_face & RAY_LEFT ? -1 : 1;
	ray->intersects.y_step = TILE / tan(angle);
	if (ray->intersects.y_step > 0 && ray->ray_face & RAY_UP)
		ray->intersects.y_step *= -1;
	if (ray->intersects.y_step < 0 && ray->ray_face & RAY_DOWN)
		ray->intersects.y_step *= -1;
}

static void	setup_vertical(t_rays *ray, float angle)
{
	ray->vertical.wall_hit |= 0;
	ray->vertical.wall_hit_x = 0;
	ray->vertical.wall_hit_y = 0;
	ray->vertical.wall_content = 0;
	setup_intersects(angle, ray);
	setup_steps(angle, ray);
	ray->vertical.next_hit_x = ray->intersects.x_intersect;
	ray->vertical.next_hit_y = ray->intersects.y_intersect;
}

void		vertical_cast(float angle, int id)
{
	float	map_x;
	float	map_y;
	t_rays	*ray;

	ray = &(store.rays[id]);
	setup_vertical(ray, angle);
	while (wall_hit(ray))
	{
		map_x = ray->vertical.next_hit_x + (ray->ray_face & RAY_LEFT ? -1 : 0);
		map_y = ray->vertical.next_hit_y;
		if (has_wall_at(map_x, map_y))
		{
			ray->vertical.wall_hit_x = ray->vertical.next_hit_x;
			ray->vertical.wall_hit_y = ray->vertical.next_hit_y;
			ray->vertical.wall_content = store.map.grid
				[(int)floor(map_y / TILE)][(int)floor(map_x / TILE)];
			ray->vertical.wall_hit |= 1;
			break ;
		}
		else
		{
			ray->vertical.next_hit_x += ray->intersects.x_step;
			ray->vertical.next_hit_y += ray->intersects.y_step;
		}
	}
}
