/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:08:16 by rvasseur          #+#    #+#             */
/*   Updated: 2026/09/29 11:08:16 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int commas(char *line)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (line[i]) {
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

static void free_color(char **to_free)
{
	int i;
	i = 0;

	if (!to_free)
		return;
	while (to_free[i]) {
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

static int validate_color_loop(char **rbg, int i)
{
	int j;
	int val;

	j = 0;
	while ((rbg[i][j] == ' ' || rbg[i][j] == '\t') && rbg[i][j])
		j++;
	if (!rbg[i][j])
		return (-1);
	while ((rbg[i][j] >= '0' && rbg[i][j] <= '9') && rbg[i][j])
		j++;
	while ((rbg[i][j] == ' ' || rbg[i][j] == '\t') && rbg[i][j])
		j++;
	if (rbg[i][j])
		return (-1);
	val = ft_atoi(rbg[i]);
	if (val < 0 || val > 255)
		return (-1);
	return val;
}

int validate_color(t_data *data, char *line, int pos)
{
	int i;
	char **rbg;
	int color[3];

	if (commas(line) != 2)
		return (ft_putendl_fd("Error commas in color conf", 2), 0);
	rbg = ft_split(line, ',');
	if (!rbg[0] || !rbg[1] || !rbg[2] || rbg[3])
		return (free_color(rbg), ft_putendl_fd("Error color", 2), 0);
	i = 0;
	while (rbg[i]) {
		color[i] = validate_color_loop(rbg, i);
		if (color[i] == -1)
			return (free_color(rbg), ft_putendl_fd("Error Color", 2), 0);
		i++;
	}
	if (pos == FLOOR)
		data->map.cfloor = (color[0] << 16) | (color[1] << 8) | color[2];
	if (pos == CEILING)
		data->map.ceiling = (color[0] << 16) | (color[1] << 8) | color[2];

	return (free_color(rbg), 1);
}
