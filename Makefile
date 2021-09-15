# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 11:50:22 by fbafica           #+#    #+#              #
#    Updated: 2021/09/13 16:31:51 by fbafica          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client server

CLIENT = client
SERVER = server

CLIENT_SOURCE = ./source/client.c
SERVER_SOURCE = ./source/server.c
UTILS_SOURCE = ./source/utils.c

INCLUDE_PATH = ./includes/
FLAGS = -Wall -Wextra -Werror

FT_PRINTF_PATH = ./ft_printf/
FT_PRINTF_INCLUDE = ./ft_printf/includes/
FT_PRINTF = ./ft_printf/ft_printf.a

CC = gcc

all: $(NAME)

$(NAME):

$(CLIENT): $(CLIENT_SOURCE) $(UTILS_SOURCE) $(FT_PRINTF)
	@$(CC) $(FLAGS) -I$(INCLUDE_PATH) -I$(FT_PRINTF_INCLUDE) $^ -o $@

$(SERVER): $(SERVER_SOURCE) $(UTILS_SOURCE) $(FT_PRINTF)
	@$(CC) $(FLAGS) -I$(INCLUDE_PATH) -I$(FT_PRINTF_INCLUDE) $^ -o $@

$(FT_PRINTF):
	@make -C $(FT_PRINTF_PATH)

clean:
	@make clean -C $(FT_PRINTF_PATH)
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)
	@make fclean -C $(FT_PRINTF_PATH)

re: fclean all
