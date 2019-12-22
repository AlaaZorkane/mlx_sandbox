#include "cub3d.h"

void init()
{
	map_setup();
	image_setup();
	store.mlx.mlx = mlx_init();
	store.mlx.window = mlx_new_window(store.mlx.mlx, store.img.width, store.img.height, "MLX - SANDBOX");
	player_setup();
}

void dispatch() {
	player_move();
	cast_rays();
	project();
	render();
}

int main()
{
	init();
	render();
	/* mlx_hook(mlx.win, 17, 0, kill, (void *)0);
	mlx_hook(mlx.win, 2, 0, key_hook, (void *)0);
	mlx_mouse_hook(mlx.win, mouse_hook, (void *)0); */
	mlx_loop(store.mlx.mlx);
}
