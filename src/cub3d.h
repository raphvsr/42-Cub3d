

#ifndef CUB3D_H
#define CUB3D_H

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

#include <stdio.h>
#include <string.h>

typedef struct s_map {
	char *textures[4];
	int cfloor;
	int ceiling;
	void *mlx_ptr;
	void *win_ptr;
	char **grid;
	int x;
	int y;
} t_map;

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

} t_data;

// MAP
int validate_cube(t_data *data, char *f_path);
int validate_texture(t_data *data, char *path, int pos);
int validate_color(t_data *data, char *line, int pos);
void get_map_size(t_data *data, char *filename);
int validate_file(char *filename);
void fill_cube_map(t_map *cube, char *f_path);
int check_wall(t_data *data);
int pars_conf(t_data *data, char *filename);

#endif
