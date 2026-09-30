/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:16:11 by rvasseur          #+#    #+#             */
/*   Updated: 2026/09/29 11:21:48 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int validate_texture(t_data *data, char *path, int pos)
{
	int test_fd;
	(void)data;
	(void)pos;
	test_fd = open(path, O_RDONLY);
	if (test_fd < 0)
		return (ft_putendl_fd("Cannot open one of the texture file", 2), 2);
	close(test_fd);
	return 0;
}
