# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 11:23:10 by jwilen            #+#    #+#              #
#    Updated: 2019/12/13 11:37:32 by amurtone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = 
OBJ = $(subst .c,.o,$(SRCS))
HEADER = includes/fdf.h
FLAGS = -Wall -Wextra -Werror
ATTATCH = -lmlx -framework OpenGL -framework AppKit -L./libft -lft
LIBFT = libft/

all: $(NAME)

$(NAME): 
	make -C $(LIBFT)
	gcc $(FLAGS) $(SRCS) -I $(HEADER) 
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(ATTATCH)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
