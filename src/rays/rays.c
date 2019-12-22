/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 11:14:27 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/22 20:38:24 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rays_setup()
{
	store.rays = malloc(store.img.width);
}

float	prepare_angle(float angle, int id)
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

void	cast_ray(float angle, int id)
{
	float horizontal_distance;
	float vertical_distance;

	horizontal_distance = horizontal_cast(angle, id);
	vertical_distance = vertical_cast(angle, id);
}

void	cast_rays()
{
	int		id;
    float	angle;
	float	fov;

	id = -1;
	fov = 60 * (M_PI / 180);
	angle = store.player.rotation_angle - fov / 2;
	while (++id < store.img.width)
	{
		angle = prepare_angle(angle, id);
		car_ray(angle, id);
        angle += fov / store.img.width;
	}
}
