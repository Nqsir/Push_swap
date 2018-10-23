# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/06/29 17:49:25 by vsteyaer     #+#   ##    ##    #+#        #
#    Updated: 2018/06/29 18:33:59 by vsteyaer    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ../checker

FLAGS = -Wall -Wextra -Werror

DIR_SRC = ./srcs/
DIR_INC = ./includes/
DIR_OBJ = ./objs/
DIR_LIBFT = ../libft/

INC = ./includes/checker.h

SRC_FILES = main.c \
		check.c \
		create.c \
		push.c \
		rotate.c \
		swap.c \
		switch.c \
		utils.c \

SRC = $(addprefix $(DIR_SRC), $(SRC_FILES))
OBJ = $(addprefix $(DIR_OBJ), $(SRC_FILES:.c=.o))
LIBFT = $(addprefix $(DIR_LIBFT), libft.a)
LIB = -L $(DIR_LIBFT) -lft

all: $(NAME)

$(NAME): $(DIR_OBJ) $(LIBFT) $(OBJ)
	@printf "Compilation of \033[1m$@\033[0m ...⌛️  \n"
	@gcc $(OBJ) $(LIB) -o $(NAME)
	@echo " 💎 💎 💎  EXECUTABLE CHECKER CREATED 💎 💎 💎  "

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(LIBFT):
	@printf " Compilation of \033[1m$@\033[0m ... ⌛️ "
	@make -C $(DIR_LIBFT)
	@echo "\n 💯 💯 💯  LIBFT COMPILED IN CHECKER_FILES 💯 💯 💯  \n"

$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC)
	@gcc $(FLAGS) -I $(DIR_LIBFT) -I $(DIR_INC) -o $@ -c $<

clean:
	@rm -Rf $(DIR_OBJ)
	@make -C $(DIR_LIBFT) clean
	@echo "\n ❌ ❌ ❌  CHECKER OBJS DELETED ❌ ❌ ❌  \n"

fclean: clean
	@rm -f $(NAME)
	@make -C $(DIR_LIBFT) fclean
	@echo "\n ⚠️ ⚠️ ⚠️  CHECKER EXECUTABLE DELETED ⚠️ ⚠️ ⚠️  \n"

re: fclean all

.PHONY: all clean fclean re
