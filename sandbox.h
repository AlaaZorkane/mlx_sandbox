#if !defined(SANDBOX_H)
#define SANDBOX_H
#include <mlx.h>
#include "key.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "player.h"
#define WIN_WIDTH 929
#define WIN_HEIGHT 449
#define MOVE_UP 0
#define MOVE_RIGHT 1
#define MOVE_DOWN 2
#define MOVE_LEFT 3
#define TILE_SIZE 32
#define MAP_Y 14
#define MAP_X 29

typedef struct s_img
{
	void	*img;
	int		*data;
	int		matrix[WIN_HEIGHT][WIN_WIDTH ];
	int		bus;
	int		bpp;
	int		endian;
} t_img;

typedef struct s_store
{

} t_store;

typedef struct s_player
{
	double x;
	double y;
	double step;
	double rotation_angle;
	double rotation_speed;
	char **map;
} t_player;

typedef struct s_mlx
{
	void 	*mlx;
	void 	*win;
	t_store	store;
	t_img 	img;
} t_mlx;

t_mlx mlx;
t_player player;

void matrix_clear(int color);
void rect(int x, int y, int x_len, int y_len, int color, int stroke);
void draw_map();
void init_map();
#endif // SANDBOX
