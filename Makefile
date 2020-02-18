# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 09:12:50 by rmarni            #+#    #+#              #
#    Updated: 2019/12/03 10:02:40 by rmarni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CH 	=	checker
NAME_PS		=	push_swap

RANDOM_NUM	=	rand_gen/a.out
#RANDOM_NUM	=	38 74 67 44 27 21 91 6 97 86 73 62 17 26 5 24 59 54 89 71 20

#						*****	OBJECT FILES	******
SRC_CHK 	=	exit_checker.o ft_atoi.o ft_cmd.o ft_print_func.o ft_sort_int.o \
            	ft_str_arg.o main.o

SRC_PS		=	drum_alg.o exit_checker.o final_func.o ft_atoi.o ft_cmd.o ft_cmd_norma.o \
            	ft_sort_int.o ft_sort_three.o ft_str_arg.o heart.o main.o best_alg.o

SRCDIR_CHK	= 	$(addprefix ./dir_check/, $(SRC_CHK))
SRCDIR_PS	=	$(addprefix ./dir_push/, $(SRC_PS))
LIBDIR		=	./libft/

#						*****	COLLORS			*****
GREEN 		=	\033[0;32m
RED 		=	\033[0;31m 
YELLOW		=	\033[0;33m 
RESET 		= 	\033[0m


CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME_CH) $(NAME_PS)

%.o: %.c
				@echo "$(GREEN)PushSwap:$(RESET) [Compilation:$(YELLOW) $@$(RESET)]"
				@$(CC) -o $@ -c $< $(CFLAGS)

$(NAME_CH): lib $(SRCDIR_CHK)
				@echo "$(NAME_PS): creating checker...$(GREEN) OK!$(RESET)"
				@$(CC) $(CFLAGS) $(SRCDIR_CHK) -o $(NAME_CH) -L $(LIBDIR) -lft

$(NAME_PS): lib $(SRCDIR_PS)
				@echo "$(NAME_PS): creating push_swap...$(GREEN) OK!$(RESET)"
				@$(CC) $(CFLAGS) $(SRCDIR_PS) -o $(NAME_PS) -L $(LIBDIR) -lft

lib:
				@echo "$(NAME_PS): creating LIBFT...$(GREEN)OK!$(RESET)"
				@make -C $(LIBDIR)

clean:
				@make -C libft/ clean
				@rm -rf $(SRCDIR_CHK)
				@rm -rf $(SRCDIR_PS) 

fclean:
				@echo "$(NAME_PS): delete all files...$(GREEN) OK!$(RESET)"
				@make -C libft/ fclean
				@make clean
				@rm -rf ./push_swap
				@rm -rf ./checker

re: fclean all
	
demo:
				./push_swap $(RANDOM_NUM) | ./checker -v $(RANDOM_NUM)

.PHONY: re clean fclean all lib demo

