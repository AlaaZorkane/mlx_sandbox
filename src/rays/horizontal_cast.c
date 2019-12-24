/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_cast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 12:40:12 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/22 22:28:15 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int wall_hit(t_rays *ray)
{
	if (ray->horizontal.next_hit_x >= 0)
		if (ray->horizontal.next_hit_x <= store.img.width)
			if (ray->horizontal.next_hit_y >= 0)
					return (ray->horizontal.next_hit_y <= store.img.height);
	return (0);
}

static void	setup_intersects(float angle, t_rays *ray)
{
	ray->intersects.y_intersect = floorf(store.player.y / TILE) * TILE;
	ray->intersects.y_intersect += ray->ray_face & RAY_DOWN ? TILE : 0;
	ray->intersects.x_intersect = store.player.x +
		(ray->intersects.y_intersect - store.player.y) / tanf(angle);
}

static void	setup_steps(float angle, t_rays *ray)
{
	ray->intersects.y_step = TILE;
	ray->intersects.y_step *= ray->ray_face & RAY_UP ? -1 : 1;
	ray->intersects.x_step = TILE / tanf(angle);
	if (ray->intersects.x_step > 0 && ray->ray_face & RAY_LEFT)
		ray->intersects.x_step *= -1;
	if (ray->intersects.x_step < 0 && ray->ray_face & RAY_RIGHT)
		ray->intersects.x_step *= -1;
}

static void	setup_horizontal(t_rays *ray, float angle, int id)
{
	setup_intersects(angle, ray);
	setup_steps(angle, ray);
	ray->horizontal.next_hit_x = ray->intersects.x_intersect;
	ray->horizontal.next_hit_y = ray->intersects.y_intersect;
}

void		horizontal_cast(float angle, int id)
{
	float	map_x;
	float	map_y;
	t_rays	*ray;

	ray = &(store.rays[id]);
	setup_horizontal(ray, angle, id);
	while (wall_hit(ray))
	{
		map_x = ray->horizontal.next_hit_x;
		map_y = ray->horizontal.next_hit_y + (ray->ray_face & RAY_UP ? -1 : 0);
		if (has_wall_at(map_x, map_y))
		{
			ray->horizontal.wall_hit_x = ray->horizontal.next_hit_x;
			ray->horizontal.wall_hit_y = ray->horizontal.next_hit_y;
			ray->horizontal.wall_content = store.map.grid
				[(int)floorf(map_y / TILE)][(int)floorf(map_x / TILE)];
			ray->horizontal.wall_hit |= 1;
			break ;
		}
		else
		{
			ray->horizontal.next_hit_x += ray->intersects.x_step;
			ray->horizontal.next_hit_y += ray->intersects.y_step;
		}
	}
}
