/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 01:06:13 by rvasseur          #+#    #+#             */
/*   Updated: 2026/10/04 05:11:00 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include "libft.h"

static char *get_value(char *line)
{
	while (*line && *line != ' ' && *line != '\t')
		line++;
	return (ft_strtrim(line, " \t\n"));
}

static int check_id(t_data *data, char *line)
{
	char *val;
	int ret;

	ret = 0;
	val = get_value(line);
	if (!strncmp(line, "NO ", 3))
		ret = validate_texture(data, val, NORTH);
	else if (!strncmp(line, "SO ", 3))
		ret = validate_texture(data, val, SOUTH);
	else if (!strncmp(line, "WE ", 3))
		ret = validate_texture(data, val, WEST);
	else if (!strncmp(line, "EA ", 3))
		ret = validate_texture(data, val, EAST);
	else if (!strncmp(line, "F ", 2))
		ret = validate_color(data, val, FLOOR);
	else if (!strncmp(line, "C ", 2))
		ret = validate_color(data, val, CEILING);
	free(val);
	return (ret);
}

static int loop_path(t_data *data, int fd)
{
	char *line;
	int count;

	count = 0;
	while (count < 6) {
		line = get_next_line(fd);
		if (!line)
			break;
		if (!is_empty(line)) {
			if (!check_id(data, line))
				return (free(line), ft_putendl_fd("Error conf", 2), 0);
			count++;
		}
		free(line);
	}
	if (count != 6)
		return (ft_putendl_fd("Missing conf in .cub file", 2), 0);
	return (1);
}

int pars_conf(t_data *data, char *filename)
{
	int fd;
	int res;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Cant open file", 2), 0);
	res = loop_path(data, fd);
	return (get_next_line(-1), close(fd), res);
}
