

#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_data data;
	if (argc != 2)
		return (ft_putendl_fd("Usage: ./cub3d map_name.cub", 2), 1);
	if (!validate_cube(&data, argv[1]))
		return (1);
	return 0;
}
