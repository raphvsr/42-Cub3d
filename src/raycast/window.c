/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <raphael.vasseur@proton.me>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 02:02:27 by rvasseur          #+#    #+#             */
/*   Updated: 2026/10/16 02:16:02 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    close_game(t_data *data)
{
	if (data->img.img_ptr)
		mlx_destroy_image(data->backend.mlx_ptr, data->img.img_ptr);
	if (data->backend.win_ptr)
		mlx_destroy_window(data->backend.mlx_ptr, data->backend.win_ptr);
	if (data->backend.mlx_ptr)
	{
		mlx_destroy_display(data->backend.mlx_ptr);
		free(data->backend.mlx_ptr);
	}
	free_data(data);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307) // ESC
		close_game(data);
	return (0);
}
