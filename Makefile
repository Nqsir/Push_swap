# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/16 16:16:29 by vsteyaer     #+#   ##    ##    #+#        #
#    Updated: 2018/06/29 18:46:59 by vsteyaer    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all checker push_swap clean fclean re clean_checker clean_push_swap fclean_checker fclean_push_swap

P1= ./checker_files/
P2= ./push_swap_files/

all : checker push_swap

checker:
	@echo "\n 💵  💵  💵  CHECKER 💵  💵  💵  \n"
	@make -C $(P1)

push_swap:
	@echo "\n 💰 💰 💰  PUSH_SWAP 💰 💰 💰  \n"
	@make -C $(P2)

clean : clean_checker clean_push_swap

clean_checker:
	@make -C $(P1) clean

clean_push_swap:
	@make -C $(P2) clean

fclean : fclean_checker fclean_push_swap

fclean_checker:
	@make -C $(P1) fclean

fclean_push_swap:
	@make -C $(P2) fclean

re : fclean all
