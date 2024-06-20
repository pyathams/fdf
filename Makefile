# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 17:20:24 by pyathams          #+#    #+#              #
#    Updated: 2024/06/20 17:29:56 by pyathams         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = fdf
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
SRC = main.c args_handle.c color.c draw.c draw_utilis.c error.c ft_atoi_base.c \
      keycodes_functions.c map_utilis2.c map_utilis1.c mlx_hook.c mlx_main.c \
      mlx_utilis.c other_utilis.c
OBJ = $(SRC:.c=.o)
INCLUDES = -Imlx_linux -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS = -L$(MLX_DIR) -lmlx_Linux -L$(LIBFT_DIR) -lft -lXext -lX11 -lm -lz

# Targets
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS) $(INCLUDES)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(LIBFT_LIB)
	rm -f $(MLX_LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

