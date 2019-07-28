# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 10:41:38 by lusanche          #+#    #+#              #
#    Updated: 2019/06/06 16:10:27 by lusanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEAD = includes/libft.h
SRCS = ft*.c
OBJS = *.o

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRCS) -I $(HEAD)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "[INFO] Library [$(NAME)] created (objects remaining in directory)"

.PHONY: all, clean, fclean, re

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] Library [$(NAME)] removed"

re: fclean all
