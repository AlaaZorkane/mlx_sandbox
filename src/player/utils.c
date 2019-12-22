/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:07:03 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/22 11:28:32 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_player_direction(char direction)
{
	if (direction == 'N')
		store.player.rotation_angle = (3 * M_PI) / 2;
	else if (direction == 'E')
		store.player.rotation_angle = 0;
	else if (direction == 'S')
		store.player.rotation_angle = M_PI / 2;
	else if (direction == 'W')
		store.player.rotation_angle = M_PI;
}

void set_player_coords()
{
	char	**objects;
	int		index;
	char	dictio;

	dictio = strdup("NESW");
	objects = store.map.objects;
	index = 0;
	while (index < store.map.object_count)
	{
		if (strchr(dictio, objects[index][0]))
		{
			store.player.x = objects[index][1] - '0';
			store.player.y = objects[index][2] - '0';
			set_player_direction(objects[index][0]);
			free(dictio);
			break ;
		}
	}
	free(dictio);
}
