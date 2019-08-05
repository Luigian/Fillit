# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 12:23:10 by lusanche          #+#    #+#              #
#    Updated: 2019/07/31 22:57:35 by lusanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = clang
FLAGS = -Wall -Wextra -Werror
INCLUDES = libft/includes
SRCS = main.c fillit.c read.c solve_1.c solve_2.c
OBJS = *.o
LIB_DIR = libft/

$(NAME):
	@make -C $(LIB_DIR) fclean && make -C $(LIB_DIR)
	@$(CC) $(FLAGS) -I $(INCLUDES) -c $(SRCS)
	@$(CC) -o $(NAME) $(OBJS) -I $(INCLUDES) -L $(LIB_DIR) -lft
	@echo "[INFO]  Executable [$(NAME)] created (objects remaining in both directories)"

.PHONY: all, clean, fclean, re

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_DIR) fclean 
	@echo "[INFO] Objects removed in both directories"
	@rm -f .DS* && rm -f ._*
	@echo "[INFO] ._files removed"


fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] Executable [$(NAME)] removed"

re: fclean all
