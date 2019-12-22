/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 11:37:13 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/21 13:42:13 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_move() {
    float	velocity;
	
	velocity = store.player.walk_direction * store.player.walk_speed;
    store.player.rotation_angle += store.player.turn_direction * store.player.turn_speed;
	store.player.y += sin(store.player.rotation_angle) * velocity;
	store.player.x += cos(store.player.rotation_angle) * velocity;
}

void player_setup()
{
	set_player_coords();
    store.player.turn_direction = 0;
    store.player.walk_direction = 0;
    store.player.walk_speed = 50;
    store.player.turn_speed = 45 * (M_PI / 180);
}
