/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:01:41 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/24 00:18:09 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYS_H
# define FT_RAYS_H
# include "cub3d.h"
# define RAY_UP (1 << 0)
# define RAY_RIGHT (1 << 1)
# define RAY_DOWN (1 << 2)
# define RAY_LEFT (1 << 3)

typedef struct	s_intersect {
	float 				x_intersect;
	float				y_intersect;
	float				x_step;
	float				y_step;
}	t_intersect;

typedef struct	s_direction_cast {
    char				wall_content;
	int 				wall_hit:1;
    float				wall_hit_x;
    float				wall_hit_y;
    float				next_hit_x;
    float				next_hit_y;
}	t_direction_cast;

typedef	struct	s_projection {
	int		line_height;
	int		wall_top;
	int		wall_bottom;
	float	wall_distance;
	float	wall_height;
	float	plane_distance;
}	t_projection;

typedef struct	s_rays {
	char				ray_face;
    char 				wall_content;
    int 				vertical_flag;
    float 				wall_x;
    float 				wall_y;
	float 				ray_angle;
    float 				distance;
	t_direction_cast	horizontal;
	t_direction_cast	vertical;
	t_intersect 		intersects;
	t_projection		projection;
} 	t_rays;

void		horizontal_cast(float angle, int id);
void		vertical_cast(float angle, int id);
void		cast_rays();
void		rays_setup();
void		project();
#endif
