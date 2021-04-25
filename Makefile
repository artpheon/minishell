# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khermann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 00:26:28 by khermann          #+#    #+#              #
#    Updated: 2021/04/23 13:33:38 by hrobbin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = minishell.h

SRCS =	main.c \
		term/terminal.c \
		term/term_utils.c \
		term/term_hist.c \
		term/term_cd.c \
		term/term_add_func.c \
		dictionary/dict1.c \
		dictionary/dict2.c \
		parser/parser.c \
		parser/lexer.c \
		parser/lexer_extra.c \
        parser/lexer_get_env.c \
        parser/lexer_line_to_args.c \
        parser/lexer_pipe.c \
        parser/lexer_quotes.c \
        parser/lexer_redirect.c \
        parser/lexer_utils.c \
		parser/validation.c \
		parser/create_commands.c \
		parser/create_commands_utils.c \
		parser/create_commands_argslen.c \
       	parser/parser_free.c \
		executor/executor.c \
		executor/exec_io.c \
		executor/exec_commands_1.c \
		executor/exec_commands_2.c \
		executor/exec_commands_3.c \
		executor/exec_cmd.c \
		executor/exec_utils.c \
		executor/exec_utils_extra_1.c \
		executor/exec_utils_extra_2.c \
		executor/env_utils.c \
		utils.c

OBJS		=	$(SRCS:.c=.o)

CC      	=   clang

%.o: %.c
	$(CC) $(INC) $(CFLAGS) -g -c $< -o ${<:.c=.o}

CFLAGS  	=   -Wall -Wextra -Werror

LIBFT   	=   libft.a

LTRMC		= -ltermcap

INC			=	-I. \
				-I./libft \
				-I./dictionary/

all:	$(NAME)

$(NAME): $(OBJS) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LTRMC) -L. $(LIBFT) -o $(NAME)


$(LIBFT): 
			make bonus -C libft ; mv libft/libft.a .
clean:	
		make clean -C libft
		rm -f $(OBJS)

fclean: clean 
		make fclean -C libft
		rm -f $(NAME)
		rm -f libft.a

re:		fclean
		make

.PHONY: all clean fclean re
