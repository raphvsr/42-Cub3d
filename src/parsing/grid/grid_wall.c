

#include "cub3d.h"
#include "get_next_line.h"

static int is_not_wall(t_map *map, int y, int x)
{
	char pos[] = "NWES0";
	int i;

	i = 0;
	while (pos[i]) {
		if (map->grid[y][x] == pos[i])
			return (1);
		i++;
	}
	return (0);
}

static int check_adjacent(t_map *map, int y, int x)
{
	int xoffset[] = {0, 0, -1, 1};
	int yoffset[] = {-1, 1, 0, 0};
	int i;
	int newx;
	int newy;

	i = 0;
	while (i < 4) {
		newx = x + xoffset[i];
		newy = y + yoffset[i];
		// outside of map verticaly ?
		if (newy < 0 || newy >= map->y)
			return 0;
		// outside of map horizontaly ?
		if (newx < 0 || newx >= (int)ft_strlen(map->grid[newy]))
			return 0;
		// adjacent is empty ?
		if (map->grid[newy][newx] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int check_wall(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (y < data->map.y) {
		x = 0;
		while (x < data->map.x) {
			if (is_not_wall(&data->map, y, x))
				if (!check_adjacent(&data->map, y, x))
					return 0;
			x++;
		}
		y++;
	}
	return 1;
}
