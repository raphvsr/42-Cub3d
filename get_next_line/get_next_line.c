/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:06:34 by marvin            #+#    #+#             */
/*   Updated: 2026/01/22 20:14:16 by rvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *next_s(char *stash) {
  size_t i;
  size_t len;
  char *next_stash;

  len = 0;
  while (stash[len] && stash[len] != '\n')
    len++;
  if (!stash[len])
    return (free(stash), NULL);
  next_stash = malloc(sizeof(char) * (ft_strlen(stash) - len + 1));
  if (!next_stash)
    return (free(stash), NULL);
  i = 0;
  len++;
  while (stash[len])
    next_stash[i++] = stash[len++];
  next_stash[i] = '\0';
  free(stash);
  return (next_stash);
}

static char *line_s(char *stash) {
  size_t i;
  char *line;

  i = 0;
  if (!stash || !stash[i])
    return (NULL);
  while (stash[i] && stash[i] != '\n')
    i++;
  line = malloc(sizeof(char) * (i + 2));
  if (!line)
    return (NULL);
  i = 0;
  while (stash[i] && stash[i] != '\n') {
    line[i] = stash[i];
    i++;
  }
  if (stash[i] == '\n') {
    line[i] = stash[i];
    i++;
  }
  line[i] = '\0';
  return (line);
}

static char *mstash(int fd, char *stash) {
  char *buffer;
  ssize_t r_bytes;

  buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
  if (!buffer)
    return (NULL);
  r_bytes = 1;
  while (!ft_strchr(stash, '\n') && r_bytes > 0) {
    r_bytes = read(fd, buffer, BUFFER_SIZE);
    if (r_bytes == 0)
      break;
    if (r_bytes == -1) {
      free(buffer);
      free(stash);
      return (NULL);
    }
    buffer[r_bytes] = '\0';
    stash = gnl_strjoin(stash, buffer);
  }
  free(buffer);
  return (stash);
}

char *get_next_line(int fd) {
  static char *stash;
  char *line;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
  stash = mstash(fd, stash);
  if (!stash)
    return (NULL);
  line = line_s(stash);
  stash = next_s(stash);
  return (line);
}
