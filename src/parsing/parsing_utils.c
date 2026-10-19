/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 03:05:53 by rvasseur          #+#    #+#             */
/*   Updated: 2026/10/04 03:06:12 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_empty(char *line)
{
	int i;

	i = 0;
	while (line[i]) {
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return 0;
		i++;
	}
	return 1;
}

void rm_newline(char *line)
{
	int i;

	i = 0;
	while (line[i]) {
		if (line[i] == '\n') {
			line[i] = '\0';
			return;
		}
		i++;
	}
}
