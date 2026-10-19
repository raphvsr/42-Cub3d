/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_components.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:46:42 by rvasseur          #+#    #+#             */
/*   Updated: 2026/10/07 18:12:53 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int check_components(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (y < data->map.y) {
		x = 0;
		while (x < data->map.x) {
			if (ft_strrchr("NSWE", data->map.grid[y][x])) {
				data->player.player_count++;
				data->player.start_orientation = data->map.grid[y][x];
				data->player.start_x = x;
				data->player.start_y = y;
			}
			if (!ft_strrchr("NSWE01 ", data->map.grid[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	if (data->player.player_count != 1)
		return (0);
	return (1);
}
