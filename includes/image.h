/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorkane <azorkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 10:45:49 by azorkane          #+#    #+#             */
/*   Updated: 2019/12/21 11:20:07 by azorkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMAGE_H
# define FT_IMAGE_H
# include "cub3d.h"

/*
**	Image struct
**	img: Holds the pointer for mlx operations
**	data: One dimensional table that holds pixel colors along with coords
**	basically represents the picture in one dimension.
**	width/height: Image width/height
**	matrix: Holds the colors of each pixel in the screen.
**	bus: mlx configuration
**	bpp: bytes per pixel, mlx configuration
**	endian: 0/1, mlx configration
*/

typedef struct s_img
{
	void	*img;
	int		*data;
	int		width;
	int		height;
	int		**matrix;
	int		bus;
	int		bpp;
	int		endian;
}	t_img;


void	put_pixel(int x, int y, int color);
void	matrix_clear(int color);
#endif
