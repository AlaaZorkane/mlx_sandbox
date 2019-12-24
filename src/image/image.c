/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 10:45:46 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/21 11:40:43 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	matrix_clear(int color)
{
	for (size_t i = 0; i <= store.img.height; i++)
		for (size_t j = 0; j <= store.img.width; j++)
			store.img.matrix[i][j] = color;
}

void	matrix_setup()
{
	int	index;

	index = -1;
	store.img.matrix = (int **)malloc(sizeof(*store.img.matrix) * store.img.height);
	while (++index <= store.img.height)
	{
		store.img.matrix[index] =
				(int *)malloc(sizeof(**store.img.matrix) * store.img.width);
	}
}

void	image_setup()
{
	store.img.width = 900;
	store.img.height = 400;
	matrix_setup();
	matrix_clear(0);
}

void	render()
{
	int x;
	int y;

	y = -1;
	if (store.img.img)
		mlx_destroy_image(store.mlx.mlx, store.img.img);
	store.img.img = mlx_new_image(store.mlx.mlx, store.img.width, store.img.height);
	store.img.data = (int *)mlx_get_data_addr(store.img.img, &store.img.bpp,
		&store.img.bus, &store.img.endian);
	while (++y < store.img.height)
	{
		x = -1;
		while (++x < store.img.width)
			store.img.data[y * store.img.width + x] = store.img.matrix[y][x];
	}
	mlx_put_image_to_window(store.mlx.mlx, store.mlx.window, store.img.img, 0, 0);
}
