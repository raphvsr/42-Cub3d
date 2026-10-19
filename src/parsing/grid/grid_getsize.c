
#include "cub3d.h"
#include "get_next_line.h"

static int is_id(char *line)
{
	int ret;

	ret = 0;
	if (!strncmp(line, "NO ", 3))
		ret = 1;
	else if (!strncmp(line, "SO ", 3))
		ret = 1;
	else if (!strncmp(line, "WE ", 3))
		ret = 1;
	else if (!strncmp(line, "EA ", 3))
		ret = 1;
	else if (!strncmp(line, "F ", 2))
		ret = 1;
	else if (!strncmp(line, "C ", 2))
		ret = 1;
	return (ret);
}

void get_map_size(t_data *data, char *filename)
{
	char *line;
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return;
	line = get_next_line(fd);
	while (line && (is_empty(line) || is_id(line))) {
		free(line);
		line = get_next_line(fd);
		data->map.map_begin_y++;
	}
	while (line && !is_empty(line)) {
		data->map.y++;
		rm_newline(line);
		if ((int)ft_strlen(line) > data->map.x)
			data->map.x = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	get_next_line(-1);
	free(line);
	close(fd);
}
