# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 11:00:46 by atabiti           #+#    #+#              #
#    Updated: 2022/12/24 11:06:46 by atabiti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers
SRC = main.cpp
OBJ = main.o 

all: $(NAME)
$(NAME): $(OBJ)
$(OBJ):
	c++ -c $(SRC)
$(NAME):
	c++  $(OBJ) -o $(NAME)
clean :
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all