#include "sandbox.h"

void	put_pixel(int x, int y, int color)
{
	mlx.img.data[y * WIN_WIDTH + x] = color;
}

void	clear_image()
{
	bzero(mlx.img.data, WIN_WIDTH * WIN_HEIGHT * mlx.img.bpp);
}
