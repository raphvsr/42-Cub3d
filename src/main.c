

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

static void init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->map.cfloor = -1; // protection bc 0 is for black color
	data->map.ceiling = -1;
}

void free_data(t_data *data)
{
	int i;

	i = 0;
	while (i < 4) {
		if (data->map.textures[i]) {
			free(data->map.textures[i]);
			data->map.textures[i] = NULL;
		}
		i++;
	}
	if (data->map.grid) {
		i = 0;
		while (data->map.grid[i]) {
			free(data->map.grid[i]);
			data->map.grid[i] = NULL;
			i++;
		}
		free(data->map.grid);
		data->map.grid = NULL;
	}
}

int main(int argc, char *argv[])
{
	t_data data;

	init_data(&data);
	if (argc != 2)
		return (free_data(&data), ft_putendl_fd("Usage:./cub3d map.cub", 2), 1);
	if (!validate_cube(&data, argv[1]))
		return (free_data(&data), 1);
	printf("\ny = %d x = %d\n", data.map.y, data.map.x);
	init_orientation(&data);
	mlx_startup(&data);
	render_background(&data);
    mlx_hook(data.backend.win_ptr, 17, 0, (void *)close_game, &data);

	mlx_loop(data.backend.mlx_ptr);
	free_data(&data);
	return 0;
}

