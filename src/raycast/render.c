/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <raphael.vasseur@proton.me>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 03:24:50 by rvasseur          #+#    #+#             */
/*   Updated: 2026/10/19 18:06:44 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int raycast(t_data *data)
{
	int x;

	x = 0;
	while (x < WIDTH)
	{
		rayon(&data->ray, &data->player, x);
		
	}
}

void render_background(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (y < HEIGHT) {
		x = 0;
		while (x < WIDTH) {
			if (y < HEIGHT / 2)
				data->img.data[y * WIDTH + x] = data->map.ceiling; // Plafond
			else
				data->img.data[y * WIDTH + x] = data->map.cfloor; // Sol
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->backend.mlx_ptr, data->backend.win_ptr,
							data->img.img_ptr, 0, 0);
}

static int rayon(t_ray *ray, t_player *plr, double x)
{
	ray->camera_x = x * 2 / WIDTH - 1;
	ray->dir_x = plr->dir_x + (plr->plane_x * ray->camera_x);
	return 1;
}
