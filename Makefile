# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 11:00:46 by atabiti           #+#    #+#              #
#    Updated: 2023/02/14 11:28:04 by atabiti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../vector/program
SRC = ../vector/main.cpp 
OBJ = main.o

all: $(NAME)
$(NAME): $(OBJ)
$(OBJ):
	cd vector && c++ -c $(SRC)
	#  -std=c++98 -Wall -Wextra -Werror
$(NAME):
	cd vector && c++  $(OBJ) -o $(NAME)
	#  -std=c++98  -Wall -Wextra -Werror
clean :
	cd vector &&	rm -f $(OBJ)
fclean: clean
	cd vector && rm -f $(NAME)
re: fclean all
leak :re 
	valgrind --leak-check=full --show-leak-kinds=all ./program