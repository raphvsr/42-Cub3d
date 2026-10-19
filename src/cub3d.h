

#ifndef CUB3D_H
#define CUB3D_H

#define WIDTH 1280
#define HEIGHT 1080

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define ON_KEYDOWN 2
#define ON_KEYUP 3
#define ON_DESTROY 17

#include "get_next_line.h"
#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

typedef struct s_backend {
	void *mlx_ptr;
	void *win_ptr;
} t_backend;

typedef struct s_ray {
	double    camera_x;
	double    dir_x;
	double    dir_y;
	int        map_x;
	int        map_y;
	double    side_dist_x;
	double    side_dist_y;
	double    delta_dist_x;
	double    delta_dist_y;
	int        step_x;
	int        step_y;
	int        hit;
	int        side;
	double    perp_wall_dist;
	int        line_height;
	int        draw_start;
	int        draw_end;
}    t_ray;

typedef struct s_map {
	char *textures[4];
	int cfloor;
	int ceiling;
	char **grid;
	int x;
	int y;
	int map_begin_y;
} t_map;

typedef struct s_img {
	void *img_ptr;
	int *data;
	int bpp;
	int size_line;
	int endian;
} t_img;

typedef struct s_player {
	int player_count;
	char start_orientation;
	int start_x;
	int start_y;
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
} t_player;

typedef enum e_cardinal {
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3,
	CEILING = 4,
	FLOOR = 5
} t_cardinal;

typedef struct s_data {
	t_map map;
	t_player player;
	t_backend backend;
	t_img img;
	t_ray ray;
} t_data;

void free_data(t_data *data);
int	handle_keypress(int keycode, t_data *data);
int	close_game(t_data *data);

// Parsing
int is_empty(char *line);
void rm_newline(char *line);

int validate_cube(t_data *data, char *f_path);
int validate_texture(t_data *data, char *path, int pos);
int validate_color(t_data *data, char *line, int pos);

void get_map_size(t_data *data, char *filename);
int validate_file(char *filename);
int fill_cube_map(t_map *cube, char *f_path);
int check_wall(t_data *data);
int check_components(t_data *data);
int pars_conf(t_data *data, char *filename);

// mlx
void mlx_startup(t_data *data);

void render_background(t_data *data);

// raycast
void init_orientation(t_data *data);
static int rayon(t_ray *ray, t_player *plr, double x);



#endif
