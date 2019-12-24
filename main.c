#include "cub3d.h"
void init()
{
	map_setup();
	image_setup();
	store.mlx.mlx = mlx_init();
	store.mlx.window = mlx_new_window(store.mlx.mlx, store.img.width, store.img.height, "MLX - SANDBOX");
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
	render();
	mlx_hook(store.mlx.window, MLX_CROSS, 0, die, (void *)0);
	mlx_hook(store.mlx.window, MLX_KEYDOWN, 0, key_isdown, (void *)0);
	mlx_hook(store.mlx.window, MLX_KEYUP, 0, key_isup, (void *)0);
	mlx_loop(store.mlx.mlx);
}
