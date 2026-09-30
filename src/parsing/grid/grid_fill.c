
#include "cub3d.h"


static void	rm_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			return ;
		}
		i++;
	}
}

void	map_fill(t_map *map, char *f_path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(f_path, O_RDONLY);
	if (fd < 0)
		return ;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rm_newline(line);
		map->grid[i] = line;
		i++;
	}
	close(fd);
}

