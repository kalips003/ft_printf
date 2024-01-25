# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agallon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 14:57:56 by agallon           #+#    #+#              #
#    Updated: 2023/11/18 19:23:04 by agallon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CFLAGS	=	-Wall -Werror -Wextra -g2

SRC		=	struct.c tableau_3.c tools_print_2.c \
			ft_printf.c tableau_2.c tableau.c tool.c tools_print.c tools_unsigned.c


OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
		$(AR) -rcs $(NAME) $(OBJ)

bonus:	$(OBJ)
		$(AR) -rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)
fclean:	clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
