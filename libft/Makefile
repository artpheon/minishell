# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khermann <khermann@21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 04:06:51 by khermann          #+#    #+#              #
#    Updated: 2021/03/11 12:56:30 by khermann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

SRC =	ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_atof.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isspace.c\
		ft_intlen.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strcmp.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\

BONUS =	ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\

OBJ =		${SRC:.c=.o}

OBJBONUS =	${BONUS:.c=.o}

HEADER =	libft.h

all:		${NAME}

$(NAME):	${OBJ} 
			ar rc $(NAME) ${OBJ}
			ranlib $(NAME)

bonus:		$(NAME) ${OBJ} ${OBJBONUS}
			ar rc $(NAME) ${OBJ} ${OBJBONUS}
			ranlib $(NAME)

#daynamic library
so:			 ${OBJ} ${OBJBONUS}
			gcc -shared -o libft.so  ${OBJ} ${OBJBONUS}

clean:
			rm -f ${OBJ} ${OBJBONUS}

fclean:		clean
			rm -f ${NAME}

re: 		fclean all

.PHONY:		re fclean clean all
