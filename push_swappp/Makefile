# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamone <pamone@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 18:46:32 by pamone            #+#    #+#              #
#    Updated: 2023/12/16 18:46:32 by pamone           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
FLAGS = -Wall -Wextra -Werror -I./get_next_line/*.c
CC = cc
SRC = operation_a.c operations_helper.c push_swap.c push_swap_utils.c \
      b_operation.c operations_helper_one.c parse_args.c split_operation.c \
      sorting_algorithms.c list_operation.c sort.c ft_str_join.c \
      ft_radix.c instructions_radix.c ft_helper_functions.c
OBJ = $(SRC:.c=.o)

MAIN_SORT_SRC = main.c
MAIN_CHECKER_SRC = checker.c

all: $(NAME) $(CHECKER)

$(NAME): $(OBJ) main.o
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) main.o

$(CHECKER): $(OBJ) checker.o
	$(CC) $(FLAGS) -o $(CHECKER) $(OBJ) checker.o ./get_next_line/*.c

main.o: $(MAIN_SORT_SRC)
	$(CC) $(FLAGS) -c $(MAIN_SORT_SRC) -o main.o

checker.o: $(MAIN_CHECKER_SRC)
	$(CC) $(FLAGS) -c $(MAIN_CHECKER_SRC) -o checker.o

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(NAME) $(CHECKER) main.o checker.o

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
