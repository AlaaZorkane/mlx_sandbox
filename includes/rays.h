/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:01:41 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/22 11:16:16 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYS_H
# define FT_RAYS_H
# include "cub3d.h"

typedef struct s_rays {
    int 	vertical_flag;
    int 	ray_up;
    int 	ray_down;
    int 	ray_left;
    int 	ray_right;
    int 	wall_content;
    float 	wall_x;
    float 	wall_y;
	float 	ray_angle;
    float 	distance;
} 	t_rays;
#endif
