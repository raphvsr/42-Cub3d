/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 03:03:26 by rvasseur          #+#    #+#             */
/*   Updated: 2026/10/09 03:25:29 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void mlx_startup(t_data *data)
{
	data->backend.mlx_ptr = mlx_init();
	data->backend.win_ptr =
		mlx_new_window(data->backend.mlx_ptr, WIDTH, HEIGHT, "cub3d");
	data->img.img_ptr = mlx_new_image(data->backend.mlx_ptr, WIDTH, HEIGHT);
	data->img.data =
		(int *)mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
								 &data->img.size_line, &data->img.endian);
}
