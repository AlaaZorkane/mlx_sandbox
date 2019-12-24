/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:57:19 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/23 23:29:45 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_isup(int button, void *param)
{
	if (button == KEY_W || button == KEY_S)
		store.player.walk_direction = 0;
	if (button == KEY_D || button == KEY_A)
		store.player.turn_direction = 0;
	return (0);
}

int	key_isdown(int button, void *param)
{
	if (button == KEY_W)
		store.player.walk_direction = 1;
	else if (button == KEY_S)
		store.player.walk_direction = -1;
	else if (button == KEY_D)
		store.player.turn_direction = 1;
	else if (button == KEY_A)
		store.player.turn_direction = -1;
	dispatch();
	return (0);
}
/* int	key_hook(int button, void *param)
{
	(void)param;
	if (button == KEY_W)
		store.player.walk_direction = 1;
	else if (button == KEY_S)
		store.player.walk_direction = -1;
	if (button == )
	player_move();
	render();
	return (0);
} */
