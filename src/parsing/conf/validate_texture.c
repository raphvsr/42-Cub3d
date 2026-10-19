/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:16:11 by rvasseur          #+#    #+#             */
/*   Updated: 2026/10/04 05:18:42 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int validate_texture(t_data *data, char *path, int pos)
{
	int test_fd;
	test_fd = open(path, O_RDONLY);
	if (test_fd < 0)
		return (ft_putendl_fd("Cannot open one of the texture file", 2), 0);
	data->map.textures[pos] = ft_strdup(path);
	close(test_fd);
	return 1;
}
