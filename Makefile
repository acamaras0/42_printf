#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acamaras <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 14:24:03 by acamaras          #+#    #+#              #
#    Updated: 2022/01/19 14:24:14 by acamaras         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =  libftprintf.a

EXE = ft_printf

FLAGS = -Wall -Wextra -Werror

LIBFT_FOLDER = ./libft/

LIB = ./libft/libft.a

LIB_OBJ = ./libft/*.o

SRCS1 = ./src/ft_printf.c ./src/checks.c ./src/convert.c ./src/helper.c \
		./src/hex_and_octal.c ./src/int_and_uint.c ./src/len_modifiers.c ./src/pointer.c \
		./src/pointer.c ./src/string_and_char.c ./src/iffloat.c

OBJS = $(subst .c,.o,$(subst src/,,$(SRCS1)))

INCL = -I ./includes/ -I ./libft/includes/

all: $(NAME)

$(NAME): $(SRCS1)
	@make -s -C $(LIBFT_FOLDER)
	@cp $(LIB) ./$(NAME)
	@gcc $(FLAGS) $(INCLUDES) -c $(SRCS1)
	@ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	
clean:
	@rm -f $(OBJS) $(LIB_OBJ)
	@make -s clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make -s fclean -C libft
	
re: fclean all


.PHONY: clean fclean re all