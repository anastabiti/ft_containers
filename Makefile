# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 11:00:46 by atabiti           #+#    #+#              #
#    Updated: 2023/01/27 12:48:11 by atabiti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
SRC = main.cpp 
OBJ = main.o 

all: $(NAME)
$(NAME): $(OBJ)
$(OBJ):
	c++  -g -c $(SRC) -std=c++98 
# -Wall -Wextra -Werror
$(NAME):
	g++ -g $(OBJ) -o $(NAME) -std=c++98
clean :
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
leak :re 
	valgrind --leak-check=full --show-leak-kinds=all ./program