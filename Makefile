# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 11:00:46 by atabiti           #+#    #+#              #
#    Updated: 2022/12/26 09:19:17 by atabiti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a
SRC = main.cpp 
OBJ = main.o 

all: $(NAME)
$(NAME): $(OBJ)
$(OBJ):
	c++ -Wall -Wextra -Werror -c $(SRC) -std=c++98
$(NAME):
	c++  -Wall -Wextra -Werror -g $(OBJ) -o $(NAME) -std=c++98
clean :
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
leak :re 
	valgrind --leak-check=full --show-leak-kinds=all ./ft_containers