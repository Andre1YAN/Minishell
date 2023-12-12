# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syan <syan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 15:09:59 by syan              #+#    #+#              #
#    Updated: 2023/12/12 15:39:07 by syan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minishell

LIBFT_PATH			=	./libft
LIBFT				=	$(LIBFT_PATH)/libft.a

OBJ_DIR				=	./obj
OBJS				=	$(SRC:%.c=$(OBJ_DIR)/%.o)

HEADER_PATH			=	./includes
HEADER_FILES		=	defines.h minishell.h

SRC					=	$(SYSTEM)									\
						$(PROMPT)									\
						$(LEXER)									\
						$(EXPANDER)									\
						$(PARSER)									\
						$(BUILTINS)									\
						$(COMMANDS)									\
						$(EXECUTER)								

SYSTEM				=	main.c										\
						error_handling.c							\
						destroyers.c								\
						init_minishell.c							\
						signals.c						
						

PROMPT				=	prompt.c

LEXER				=	tokens.c									\
						handle_spaces.c								\
						create_token_list.c							\
						utils_lexer.c								\

EXPANDER			=	expander.c									\
						brace_expansion.c

PARSER 				=	parser.c 									\
						handle_metachars.c							\
						error_parser.c								\
						handle_quotes.c
						
BUILTINS 			=	env.c

DIRS				=	. lexer prompt expander parser builtins executer commands system
IFLAGS				=	-I $(HEADER_PATH)
LDFLAGS				=	-L$(LIBFT_PATH) -lft
CFLAGS				=	-Wall -Wextra -Werror

VPATH				=	$(addprefix ./src/, $(DIRS))
VPATH				+=	$(HEADER_PATH)

CFLAGS				+=	-g

WHITE				=	\e[00m
GREEN				=	\e[32m
RED					=	\e[91m
YELLOW				=	\e[033m
BLUE				=	\e[34m

NUMBER_OF_SRC_FILES	=	$(words $(SRC))
PROGRESS			=	0

all: $(NAME)

clean:
	rm -rf obj
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)

re:  fclean all

$(LIBFT):
	make -C $(LIBFT_PATH)
	make bonus -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJS) $(LDFLAGS) -lreadline
	@echo "$(GREEN)MINISHELL compiled succesfully$(WHITE)"

$(OBJ_DIR)/%.o: %.c $(HEADER_FILES) Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo -n "$(YELLOW)Compiling $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_SRC_FILES)))%\r"
	$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))

$(OBJ_DIR):
	mkdir -p $@

.PHONY:	all clean fclean re