# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 11:00:46 by atabiti           #+#    #+#              #
#    Updated: 2022/12/25 13:31:14 by atabiti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers
SRC = main.cpp vector.cpp
OBJ = main.o vector.o

all: $(NAME)
$(NAME): $(OBJ)
$(OBJ):
	c++ -c $(SRC)
$(NAME):
	c++  -g $(OBJ) -o $(NAME)
clean :
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
leak :re 
	valgrind --leak-check=full --show-leak-kinds=all ./ft_containers