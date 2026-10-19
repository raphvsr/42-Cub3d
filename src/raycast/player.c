/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <raphael.vasseur@proton.me>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 00:46:42 by rvasseur          #+#    #+#             */
/*   Updated: 2026/10/19 18:39:34 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_orientation(t_data *data)
{
	data->player.pos_x = (double)data->player.start_x + 0.5;
	data->player.pos_y = (double)data->player.start_y + 0.5;

	if (data->player.start_orientation == 'N') {
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	} else if (data->player.start_orientation == 'W') {
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
	} else if (data->player.start_orientation == 'S') {
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
	} else if (data->player.start_orientation == 'E') {
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
	}
}

int step(t_data *data)
{
	
}
