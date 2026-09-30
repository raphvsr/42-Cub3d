# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvasseur <rvasseur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/30 01:50:00 by rvasseur          #+#    #+#              #
#    Updated: 2026/09/30 01:50:00 by rvasseur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3d

# Compiler and Flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
INCLUDES    = -Isrc -Ilibft -Iget_next_line -I$(MLX_DIR)

# Directories
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a

OBJ_DIR     = obj

# Sources
SRCS        = src/main.c \
              src/parsing/conf/conf_parsing.c \
              src/parsing/conf/validate_color.c \
              src/parsing/conf/validate_texture.c \
              src/parsing/grid/check_args.c \
			  src/parsing/parser.c \
              src/parsing/grid/grid_fill.c \
              src/parsing/grid/grid_getsize.c \
              src/parsing/grid/grid_wall.c \
              get_next_line/get_next_line.c \
              get_next_line/get_next_line_utils.c
			  	

# Objects & Dependencies
OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS        = $(OBJS:.o=.d)

# Libraries & Linker Flags (Linux)
LIBS        = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Colors for terminal output
DEF_COLOR   = \033[0;39m
GREEN       = \033[0;92m
YELLOW      = \033[0;93m
BLUE        = \033[0;94m
CYAN        = \033[0;96m
RED         = \033[0;91m

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) successfully created!$(DEF_COLOR)"

$(LIBFT):
	@echo "$(CYAN)Compiling libft...$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX_LIB):
	@echo "$(CYAN)Compiling minilibx...$(DEF_COLOR)"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory 2>/dev/null || \
		$(MAKE) -C $(MLX_DIR) -f Makefile.gen CFLAGS="-O3 -I/usr/include -std=gnu89" --no-print-directory

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling: $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	@echo "$(RED)Removing objects...$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean --no-print-directory 2>/dev/null || true; fi

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(DEF_COLOR)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
