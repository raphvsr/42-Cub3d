

#include "cub3d.h"
#include "libft.h"

int validate_file(char *filename) {
  char *x;

  x = ft_strrchr(filename, '.');
  if (!x)
    return (0);
  if (!ft_strcmp(x, ".cub"))
    return (1);
  return (0);
}
