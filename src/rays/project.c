/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 23:31:26 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/24 14:51:23 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void prepare_ray_projection(t_rays *ray)
{
	ray->projection.wall_distance =
		ray->distance * cos(ray->ray_angle - store.player.rotation_angle);
	ray->projection.plane_distance = (store.img.width / 2) / tan(FOV / 2);
	ray->projection.wall_height = (TILE / ray->projection.wall_distance)
		* ray->projection.plane_distance;
	ray->projection.line_height = (int)ray->projection.wall_height;
	ray->projection.wall_top =
		(store.img.width / 2) - ray->projection.line_height / 2;
	ray->projection.wall_bottom =
		(store.img.width / 2) - ray->projection.line_height / 2;
	if (ray->projection.wall_top < 0)
		ray->projection.wall_top = 0;
	if (ray->projection.wall_bottom > store.img.width)
		ray->projection.wall_bottom = store.img.width;
}

void		project()
{
	int		id;
	t_rays	*ray;

	id = -1;
	while (id < store.img.width)
	{
		ray = &(store.rays[id]);
		prepare_ray_projection(ray);
		draw_ceiling(ray, id);
		draw_content(ray, id);
		draw_floor(ray, id);
	}
}
