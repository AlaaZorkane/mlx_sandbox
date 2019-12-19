#include "sandbox.h"

void render()
{
	int x;
	int y;
	int color;

	mlx.img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img, &mlx.img.bpp, &mlx.img.bus, &mlx.img.endian);
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			mlx.img.data[y * WIN_WIDTH + x] = mlx.img.matrix[y][x];
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
}

void set_pixel(int x, int y, int color) {
	mlx.img.matrix[y][x] = color;
}

void rect(int x, int y, int x_len, int y_len, int color, int stroke)
{
	int index;
	int jndex;

	if (stroke == -1)
		stroke = color;
	for (index = y; index <= y + y_len; index++)
	{
		for (jndex = x; jndex <= x + x_len; jndex++)
		{
			if (index == y || jndex == x || index == y + y_len || jndex == x + x_len)
				set_pixel(jndex, index, stroke);
				//mlx.img.matrix[index][jndex] = stroke;
			else
				set_pixel(jndex, index, color);
				//mlx.img.matrix[index][jndex] = color;
		}
	}
}

void circle(int x, int y, int radius, int color) {
	int index;
	int jndex;

	for(index=-radius; index<=radius; index++)
		for(jndex=-radius; jndex<=radius; jndex++)
			if(jndex*jndex+index*index <= radius*radius)
				set_pixel(x+jndex, y+index, color);
}

void line(int x, int color)
{
	int index;

	for (index = 0; index < WIN_HEIGHT; index++)
		mlx.img.matrix[index][x] = color;
}

int mouse_hook(int button, int x, int y, void *param)
{
	(void)param;
	if (button == 1)
	{
		if (y < WIN_HEIGHT && x < WIN_WIDTH && x > 0 && y > 0)
			//rect(x, y, TILE_SIZE, TILE_SIZE, 0xFF0000, 0);
			circle(x, y, 8, 0xFF0000);
			//line(x, 0);
	}
	render();
	return (0);
}

int key_hook(int button, void *param)
{
	char allowed_moves[] = { KEY_W, KEY_D, KEY_S, KEY_A, KEY_LEFT, KEY_RIGHT };
	(void)param;
	if (button == KEY_C)
	{
		matrix_clear(0xFFFFFF);
	}
	else if (button == KEY_ESC) {
		exit(0);
	} else {
		if (strchr(allowed_moves, button))
			player_move(button);
	}
	draw_map();
	render();
	return (0);
}

int kill(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
void matrix_clear(int color)
{
	for (size_t i = 0; i < WIN_HEIGHT; i++)
		for (size_t j = 0; j < WIN_WIDTH; j++)
			mlx.img.matrix[i][j] = color;
}
void draw_map()
{
	int x;
	int y;

	for (y = 0; y < MAP_Y; y++)
	{
		for (x = 0; x < MAP_X; x++)
		{
			if (player.map[y][x] == '1')
				rect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0x454545, 0x232323);
			else
				rect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFF, 0);
		}
	}
	circle(player.x, player.y, 8, 0x880000);
}

int main()
{
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx,WIN_WIDTH, WIN_HEIGHT, "MLX - SANDBOX");
	matrix_clear(0xFFFFFF);
	init_map();
	init_player();
	draw_map();
	render();
	mlx_hook(mlx.win, 17, 0, kill, (void *)0);
	mlx_hook(mlx.win, 2, 0, key_hook, (void *)0);
	mlx_mouse_hook(mlx.win, mouse_hook, (void *)0);
	mlx_loop(mlx.mlx);
}
