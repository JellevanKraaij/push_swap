# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jvan-kra <jvan-kra@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/19 15:45:22 by jvan-kra      #+#    #+#                  #
#    Updated: 2021/12/17 21:55:19 by jvan-kra      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME  = push_swap

all: ${NAME}

${NAME}:
	mkdir -p build && cd build && cmake .. -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=.. && make
clean:
	rm -rf build

fclean: clean
	rm -f push_swap checker

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus