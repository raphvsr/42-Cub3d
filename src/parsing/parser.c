/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:17:36 by rvasseur          #+#    #+#             */
/*   Updated: 2026/10/09 03:41:11 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>

static int alloc_grid_memory(t_data *data)
{
	data->map.grid = ft_calloc(data->map.y + 1, sizeof(char *));
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

static void printerr(int nb)
{
	if (nb == 1)
		ft_putendl_fd("file is invalide or cant be oppened", 2);
	else if (nb == 2)
		ft_putendl_fd("Error parsing the config file", 2);
	else if (nb == 3)
		ft_putendl_fd("Error filling the grid", 2);
}

int validate_cube(t_data *data, char *f_path)
{
	write(2, "\n", 1);
	if (!validate_file(f_path))
		return (free_map_memory(data), printerr(1), 0);
	if (!pars_conf(data, f_path))
		return (free_map_memory(data), printerr(2), 0);
	get_map_size(data, f_path);
	if (!alloc_grid_memory(data))
		return (free_map_memory(data), printerr(3), 0);
	if (!fill_cube_map(&data->map, f_path))
		return (free_map_memory(data), printerr(4), 0);
	else if (!check_components(data))
		return (ft_putendl_fd("Invalid number of player", 2), 0);
	else if (!check_wall(data))
		return (ft_putendl_fd("Invalid Wall placement", 2), 0);
	return (1);
}
