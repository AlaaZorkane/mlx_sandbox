/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 11:14:27 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/23 23:44:56 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		rays_setup()
{
	store.rays = malloc(store.img.width);
}

static float	prepare_angle(float angle, int id)
{
	angle = normalize(angle);

	if (angle > 0 && angle < M_PI)
		store.rays[id].ray_face |= RAY_DOWN;
	else
		store.rays[id].ray_face |= RAY_UP;
	if (angle < 0.5 * M_PI || angle > 1.5 * M_PI)
		store.rays[id].ray_face |= RAY_RIGHT;
	else
		store.rays[id].ray_face |= RAY_LEFT;
}

static void		record_direction(char direction, float distance, t_rays *ray)
{
	if (direction == 'h')
	{
		ray->distance = distance;
		ray->wall_x = ray->vertical.wall_hit_x;
		ray->wall_y = ray->vertical.wall_hit_y;
		ray->wall_content = ray->vertical.wall_content;
		ray->vertical_flag = 1;
	}
	else if (direction == 'v')
	{
		ray->distance = distance;
		ray->wall_x = ray->horizontal.wall_hit_x;
		ray->wall_y = ray->horizontal.wall_hit_y;
		ray->wall_content = ray->horizontal.wall_content;
		ray->vertical_flag = 0;
	}
}

static void		record_cast(float horizontal_d, float vertical_d, float angle, int id)
{
	t_rays	*ray;

	ray = &(store.rays[id]);
	if (horizontal_d > vertical_d)
		record_direction('h', horizontal_d, ray);
	else
		record_direction('v', vertical_d, ray);
	ray->ray_angle = angle;
}

static void		cast_ray(float angle, int id)
{
	t_rays	*ray;
	float	horizontal_distance;
	float	vertical_distance;

	ray = &(store.rays[id]);
	horizontal_cast(angle, id);
	vertical_cast(angle, id);
	horizontal_distance = ray->horizontal.wall_hit
		? distance_point2point(store.player.x, store.player.y,
			ray->horizontal.wall_hit_x, ray->horizontal.wall_hit_y)
		: MAXFLOAT;
	vertical_distance = ray->vertical.wall_hit
		? distance_point2point(store.player.x, store.player.y,
			ray->vertical.wall_hit_x, ray->vertical.wall_hit_y)
		: MAXFLOAT;
	record_cast(horizontal_distance, vertical_distance, angle, id);
}

void		cast_rays()
{
	int		id;
    float	angle;

	id = -1;
	angle = store.player.rotation_angle - FOV / 2;
	while (++id < store.img.width)
	{
		angle = prepare_angle(angle, id);
		cast_ray(angle, id);
        angle += FOV / store.img.width;
	}
}
