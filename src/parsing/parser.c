

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>

static int alloc_map_memory(t_data *data)
{
	data->map.grid = malloc(sizeof(char *) * (data->map.y + 1));
	if (!data->map.grid)
		return (0);
	data->map.grid[data->map.y] = NULL;
	return (1);
}

static int free_map_memory(t_data *data)
{
	if (data->map.grid) {
		free(data->map.grid);
		data->map.grid = NULL;
	}
	return 1;
}

int validate_cube(t_data *data, char *f_path)
{
	write(2, "\n", 1);
	get_map_size(data, f_path);
	if (!alloc_map_memory(data))
		return (0);
	// fill_cube_map(&data->map, f_path);
	if (!validate_file(f_path))
		return (free_map_memory(data), ft_putendl_fd("idjwqidwq", 2), 0);
	if (!pars_conf(data, f_path))
		return (free_map_memory(data),
				ft_putendl_fd("Error\nParsing the config file", 2), 0);
	//   else if (!check_components(data))
	//     return (ft_putendl_fd("Error\nCharacter invalide", 2), 0);
	// else if (!check_wall(data))
	// 	return (ft_putendl_fd("Error\nLes murs sont invalides", 2), 0);
	//   else if (data->cube.cube_map_x < 3 || data->cube.cube_map_y < 3)
	//     return (ft_putendl_fd("Error\nMap trop petite", 2), 0);
	//   else if (data->cube.cube_map_x > 60 || data->cube.cube_map_y > 30)
	//     return (ft_putendl_fd("Error\nMap trop grande", 2), 0);
	//   else if (!map_validate(data))
	//     return (0);
	return (1);
}
