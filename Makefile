# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrettas <pdrettas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 18:22:30 by pdrettas          #+#    #+#              #
#    Updated: 2024/11/12 19:02:33 by pdrettas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC =  ft_printf.c ft_printf_utils00.c ft_printf_utils01.c ft_printf_utils02.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = libft
LIBFT = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)            
	@ar rcs $(NAME) $(OBJ) $(LIBFT_DIR)/*.o 
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)
	rm -f $(LIBFT_DIR)/*.o
	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/*.a
	
re: fclean all

.PHONY: all fclean clean re 