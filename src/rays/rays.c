/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 11:14:27 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/22 11:34:25 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rays_setup()
{
	store.rays = malloc(store.img.width);
}

void	cast_rays()
{
	int		line;
    float	angle;
	float	fov;

	line = 0;
	fov = 60 * (M_PI / 180);
	angle = store.player.rotation_angle - fov / 2;
    for (line = 0; line < store.img.width; line++) {
        car_ray(angle, line);
        angle += fov / store.img.width;
    }
}
