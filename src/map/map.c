/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 11:23:34 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/22 12:41:46 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char map_placeholder[14][29] = {
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '0', '0', 'S', '0', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '0', '1', '0', '0', '0', '1'},
	{'1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '1', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '1', '0', '0', '1', '0', '0', '0', '1'},
	{'1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
};

void	record_object(char object_id, int index, int jndex)
{
	char	**ptr;
	int		count;

	ptr = store.map.objects;
	count = store.map.object_count;
	ptr[count] = malloc(3);
	ptr[count][0] = object_id;
	ptr[count][1] = index + '0';
	ptr[count][2] = jndex + '0';
	store.map.object_count++;
}

void	read_map()
{
	char	**map;
	int		index;
	int		jndex;

	map = malloc(store.map.rows * sizeof(*map));
	index = -1;
	while (++index < store.map.rows) {
		jndex = -1;
		map[index] = malloc(store.map.cols * sizeof(**map));
		while (++jndex < store.map.cols) {
			map[index][jndex] = map_placeholder[index][jndex];
			if (map[index][jndex] != '0' && map[index][jndex] != '1')
				record_object(map[index][jndex], index, jndex);
		}
	}
	store.map.grid = map;
}

void	map_setup()
{
	store.map.object_count = 0;
	//set_dimensions();
	store.map.rows = 14;
	store.map.cols = 29;
	store.map.objects = malloc(store.map.rows * store.map.cols
		* sizeof(*store.map.objects));
	read_map();

}
