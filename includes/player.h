/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 10:45:58 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/22 11:31:19 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAYER_H
# define FT_PLAYER_H
# include "cub3d.h"

/*
**	Player struct
**	x/y: Real coord of the camera
**	turn_direction: [1 | RIGHT] [-1 | LEFT]
**	walk_direction: [1 | FRONT] [-1 | BACK]
**	rotation_angle: The rotation angle of the camera in radians
**	walk_speed: The speed of the player
**	turn_speed: Angle rotation speed
*/

typedef struct s_player
{
    int		turn_direction;
    int		walk_direction;
	float	x;
    float	y;
    float	rotation_angle;
    float	walk_speed;
    float	turn_speed;
} t_player;


void set_player_direction(char direction);
void set_player_coords();
void player_setup();
void player_move();
#endif
