/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:12:35 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/24 15:12:41 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void init()
{
	map_setup();
	store.mlx.mlx = mlx_init();
	image_setup();
	store.mlx.window = mlx_new_window(store.mlx.mlx, store.img.width, store.img.height, "MLX - SANDBOX!");
	player_setup();
}

void dispatch()
{
	player_move();
	cast_rays();
	project();
	render();
}

int main()
{
	init();
	dispatch();
	mlx_hook(store.mlx.window, MLX_CROSS, 0, die, (void *)0);
	mlx_hook(store.mlx.window, MLX_KEYDOWN, 0, key_isdown, (void *)0);
	mlx_hook(store.mlx.window, MLX_KEYUP, 0, key_isup, (void *)0);
	mlx_loop(store.mlx.mlx);
}
