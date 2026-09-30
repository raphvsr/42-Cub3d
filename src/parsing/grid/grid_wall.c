

#include "cub3d.h"

int	check_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.x)
	{
		if (data->map.grid[0][i] != '1')
			return (0);
		if (data->map.grid[data->map.y - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->map.y)
	{
		if (data->map.grid[i][0] != '1')
			return (0);
		if (data->map.grid[i][data->map.x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
