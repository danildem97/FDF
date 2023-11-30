# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddemydov <ddemydov@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 17:30:50 by ddemydov          #+#    #+#              #
#    Updated: 2023/07/25 20:01:33 by ddemydov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		matrix_parser.c \
		utils.c \
		utils2.c \
		drawing.c \
		initialization.c \
		isometric.c \
		close.c \
		colors.c \
		

NAME = fdf

LIBFT = libft/
MLX = mlx/

OBJS = $(SRCS:.c=.o)

CC = gcc -o3

CC_FLAGS =  -I/opt/X11/include -I/includes -v -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(MLX)
	mv $(MLX)/libmlx.dylib libmlx.dylib
	@$(CC) $(CC_FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) libft/libft.a ./libmlx.dylib

clean:
	@rm -rf $(OBJS)
	@make fclean -C $(LIBFT)
	@make clean -C $(MLX)

fclean: clean
	@rm -f $(NAME)
	@rm -f libmlx.dylib

re: fclean all