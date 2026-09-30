
#include "cub3d.h"

void	get_map_size(t_data *data, char *filename)
{
	char	c;
	int		fd;
	int		x;
	int		y;
	int		char_count;

	char_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	x = 0;
	y = 0;
	while (read(fd, &c, 1) > 0)
	{
		char_count++;
		if (y == 0 && c != '\n')
			x++;
		if (c == '\n')
			y++;
	}
	if ((char_count > 0 && c != '\n') || (y == 0 && x > 0))
		y++;
	close(fd);
	data->map.x = x;
	data->map.y = y;
}
