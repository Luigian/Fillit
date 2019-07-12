# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 12:23:10 by lusanche          #+#    #+#              #
#    Updated: 2019/07/11 12:33:14 by lusanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = clang
FLAGS = -Wall -Wextra -Werror
INCLUDES = libft/includes
SRC = fillit.c
OBJ = fillit.o
LIB_DIR = libft/ 

$(NAME):
	@make -C $(LIB_DIR) fclean && make -C $(LIB_DIR)
	@$(CC) $(FlAGS) -I $(INCLUDES) -o $(OBJ) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -I $(INCLUDES) -L $(LIB_DIR) -lft
	@echo "[INFO]  Executable [$(NAME)] created (objects remaining in both directories)"

.PHONY: all, clean, fclean, re

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(LIB_DIR) fclean 
	@echo "[INFO] Objects removed in both directories"
	@rm -f .DS* && rm -f ._*
	@echo "[INFO] ._files removed"


fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] Executable [$(NAME)] removed"

re: fclean all
