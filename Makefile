# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalves-d <lalves-d@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 10:44:48 by lalves-d          #+#    #+#              #
#    Updated: 2025/03/25 10:45:33 by lalves-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
MLX = minilibx-linux
MLX_LIB = $(MLX)/libmlx_Linux.a
MLXFLAGS = -L$(MLX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
SRCS = main.c fractal.c events.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLXFLAGS)

clean:
	rm -f $(OBJS)
	make clean -C $(MLX)

fclean: clean
	rm -f $(NAME)
	make clean -C $(MLX)

re: fclean all
