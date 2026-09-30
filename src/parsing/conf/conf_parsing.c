
#include "cub3d.h"
#include "libft.h"

static int loop_path(t_data *data, int fd)
{
	char *line;
	char *trim;

	while (1) {
		line = get_next_line(fd);
		if (!line)
			break;
		trim = ft_strtrim(line + 3, " \t\n");
		if (!strncmp(line, "NO ", 3))
			validate_texture(data, trim, NORTH);
		else if (!strncmp(line, "SO", 2))
			validate_texture(data, trim, SOUTH);
		else if (!strncmp(line, "WE", 2))
			validate_texture(data, trim, WEST);
		else if (!strncmp(line, "EA", 2))
			validate_texture(data, trim, EAST);
		else if (!strncmp(line, "F", 1))
			validate_color(data, trim, FLOOR);
		else if (!strncmp(line, "C", 1))
			validate_color(data, trim, CEILING);
		else if (line[0] != '\0' && line[0] != '\n')
			return (free(trim), ft_putendl_fd("Conf error", 2), 0);
	}
	return (free(trim), 1);
}

int pars_conf(t_data *data, char *filename)
{
	int fd;
	// char *line;
	// int i;
	// char *path;

	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		ft_putendl_fd("Cant open file", 2);
		return (0);
	}
	loop_path(data, fd);
	// i = 0;

	close(fd);
	return 1;
}
