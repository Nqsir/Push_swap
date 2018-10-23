# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/06/23 11:12:37 by vsteyaer     #+#   ##    ##    #+#        #
#    Updated: 2018/06/29 18:46:54 by vsteyaer    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ../push_swap

FLAGS = -Wall -Wextra -Werror

DIR_SRC = ./srcs/
DIR_INC = ./includes/
DIR_OBJ = ./objs/
DIR_LIBFT = ../libft/

INC = ./includes/push_swap.h

SRC_FILES = check.c \
			create.c \
			main.c \
			print.c \
			push.c \
			rotate.c \
			sort_type_1.c \
			sort_type_2.c \
			sort_type_3.c \
			swap.c \
			utils.c\
			opti_mvt.c

SRC = $(addprefix $(DIR_SRC), $(SRC_FILES))
OBJ = $(addprefix $(DIR_OBJ), $(SRC_FILES:.c=.o))
LIBFT = $(addprefix $(DIR_LIBFT), libft.a)
LIB = -L $(DIR_LIBFT) -lft

all: $(NAME)

$(NAME): $(DIR_OBJ) $(LIBFT) $(OBJ)
	@printf "Compilation of \033[1m$@\033[0m ...⌛️  \n"
	@gcc $(OBJ) $(LIB) -o $(NAME)
	@echo " 💎 💎 💎  EXECUTABLE PUSH_SWAP CREATED 💎 💎 💎  "

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(LIBFT):
	@printf " Compilation of \033[1m$@\033[0m ... ⌛️ "
	@make -C $(DIR_LIBFT)
	@echo "\n 💯 💯 💯  LIBFT COMPILED IN PUSH_SWAP_FILES 💯 💯 💯  \n"

$(DIR_OBJ)%.o:$(DIR_SRC)%.c $(INC)
	@gcc $(FLAGS) -I $(DIR_LIBFT) -I $(DIR_INC) -o $@ -c $<

clean:
	@rm -Rf $(DIR_OBJ)
	@make -C $(DIR_LIBFT) clean
	@echo "\n ❌ ❌ ❌  PUSH_SWAP OBJS DELETED ❌ ❌ ❌  \n"

fclean: clean
	@rm -f $(NAME)
	@make -C $(DIR_LIBFT) fclean
	@echo "\n ⚠️ ⚠️ ⚠️  PUSH_SWAP EXECUTABLE DELETED ⚠️ ⚠️ ⚠️  \n"

re: fclean all

.PHONY: all clean fclean re
