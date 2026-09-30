/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:30:12 by marvin            #+#    #+#             */
/*   Updated: 2026/01/15 00:31:51 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
char *gnl_strjoin(char *s1, char *s2);

#endif
