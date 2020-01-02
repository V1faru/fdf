# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Andreas <Andreas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 11:23:10 by jwilen            #+#    #+#              #
#    Updated: 2019/12/30 20:34:08 by Andreas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = srcs/main.c srcs/read_map.c srcs/ft_count_words.c srcs/draw_pixel.c \
	srcs/menu.c srcs/set_params.c srcs/isometric.c srcs/keys.c srcs/edit_window.c
OBJ = $(subst .c,.o,$(SRCS))
HEADER = includes/fdf.h
FLAGS = -Wall -Wextra -Werror
ATTATCH = -L resources/ -lmlx -framework OpenGL -framework AppKit -L ./libft -lft
LIBFT = libft/

all: $(NAME)

$(NAME): 
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HEADER) $(ATTATCH)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
