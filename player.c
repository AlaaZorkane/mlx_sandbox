#include "sandbox.h"

void init_player() {
	player.step = 3;
	player.rotation_speed = 5;
}

void	move_up() {
	player.x += cos(player.rotation_angle) * player.step;
	player.y += sin(player.rotation_angle) * player.step;
}
void	move_right() {
	player.x -= cos(player.rotation_angle - M_PI/2) * player.step;
	player.y -= sin(player.rotation_angle - M_PI/2) * player.step;
}
void	move_back() {
	player.x -= cos(player.rotation_angle) * player.step;
	player.y -= sin(player.rotation_angle) * player.step;
}
void	move_left() {
	player.x -= cos(player.rotation_angle + M_PI/2) * player.step;
	player.y -= sin(player.rotation_angle + M_PI/2) * player.step;
}
void	turn_right() {
	player.rotation_angle += player.rotation_speed;
}
void	turn_left() {
	player.rotation_angle -= player.rotation_speed;
}
void	player_move(int button) {
	if (button == KEY_W) {
		move_up();
	} else if (button == KEY_D) {
		move_right();
	} else if (button == KEY_S) {
		move_back();
	} else if (button == KEY_A) {
		move_left();
	} else if (button == KEY_RIGHT) {
		turn_right();
	} else if (button == KEY_LEFT) {
		turn_left();
	}
	printf("(%.2f , %.2f) | ( %.2f ) |\n", player.x, player.y, player.rotation_angle);
}

