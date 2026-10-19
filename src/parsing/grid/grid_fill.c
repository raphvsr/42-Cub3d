/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 05:05:23 by rvasseur          #+#    #+#             */
/*   Updated: 2026/10/04 05:16:57 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
// TODO: skip again all the conf and empty line
// can share with grid_getsize() ??
// need to end with map->grid[i] = NULL;

static int skip_lines(t_map *map, int fd)
{
	int i;
	char *line;

	i = 0;
	while (i < map->map_begin_y) {
		line = get_next_line(fd);
		if (!line)
			return 0;
		free(line);
		i++;
	}
	return 1;
}

static char *add_white_space(char *line, t_map *map)
{
	char *ret;
	int i;

	ret = malloc(sizeof(char) * (map->x + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n' && i < map->x) {
		ret[i] = line[i];
		i++;
	}
	while (i < map->x)
		ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

int fill_cube_map(t_map *map, char *f_path)
{
	int fd;
	char *line;
	int i;

	fd = open(f_path, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!skip_lines(map, fd))
		return (close(fd), 0);
	i = 0;
	while (i < map->y) {
		line = get_next_line(fd);
		if (!line)
			break;
		map->grid[i] = add_white_space(line, map);
		free(line);
		i++;
	}
	map->grid[i] = NULL;
	get_next_line(-1);
	close(fd);
	return (1);
}
