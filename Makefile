# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 15:16:05 by user42            #+#    #+#              #
#    Updated: 2021/04/20 16:36:20 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	libasm.a

SRCS	=	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s	\
			ft_read.s	\
			ft_strdup.s	\

OBJS	=	${SRCS:.s=.o}

RM		=	rm -f

.s.o:
			nasm -f elf64 $< -o $@

all:		${NAME}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

test:		all
			gcc -Wall -Wextra -Werror testeur.c -L. -lasm

fclean:		clean
			${RM} ${NAME}
			${RM} a.out

re:			fclean all

.PHONY:		all test clean fclean re
