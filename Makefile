# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 17:08:52 by ibaines           #+#    #+#              #
#    Updated: 2022/03/08 16:48:34 by ibaines          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRC = so_long.c \
	  ft_img.c \
	  ft_move.c \
	  ft_print.c \
	  ft_utils_m.c \
	  ft_utils2_m.c \
	  ft_collect.c \
	  ft_char_check.c


SRC_BONUS = so_long_bonus.c \
	ft_collect_bonus.c \
	ft_img_bonus.c \
	ft_print_bonus.c \
	ft_utils_bonus.c \
	ft_utils2_bonus.c \
	ft_enemy.c \
	ft_move_bonus.c \
	ft_char_check_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJS = $(SRC_BONUS:.c=.o)
HEADERS = includes/so_long.h
HEADERS_BONUS = includes/so_long_bonus.h 
CC = gcc
FLAGS = -Wall -Wextra -Werror -Imlx #-g3 -fsanitize=address
LIBFT = libft/libft.a

all: $(NAME)

$(NAME):
		@echo "\033[0;32mCOMPILING SO_LONG...\033[0m"
		@${MAKE} -s -C libft
		@${MAKE} -s -C minilibx 2>.errors
		@$(CC) $(FLAGS) -c $(SRC) -I$(HEADERS)
		@$(CC) $(FLAG) -L minilibx  -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) $(LIBFT)
		@mkdir obj
		@mv $(OBJ) ./obj
		@echo "\033[0;32mSO_LONG COMPILED\033[0m"

bonus: $(NAME_BONUS)

$(NAME_BONUS):
ifeq ($(shell test -e $(LIBFT) && echo "0"), $(shell echo "0"))
	@echo "\033[0;32mLIBFT ALREADY COMPILED...\nMLX ALREADY COMPILED...\033[0m"
else
	${MAKE} -C libft
	${MAKE} -C minilibx 2>.errors 
endif
			@$(CC) $(FLAGS) -c $(SRC_BONUS) -I$(HEADERS_BONUS)
			@$(CC) $(FLAGS) -L minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(BONUS_OBJS) $(LIBFT)
			@mkdir obj_bonus
			@mv $(BONUS_OBJS) ./obj_bonus
			@echo "\033[0;32mSO_LONG_BONUS COMPILED\033[0m"

clean:
		@/bin/rm -f $(OBJ)
		@/bin/rm -f $(OBJ_BONUS)
		@/bin/rm -Rf obj
		@/bin/rm -rf .errors
		@/bin/rm -Rf obj_bonus
		@${MAKE} -C libft clean
		@${MAKE} -C minilibx clean

fclean: clean
		@/bin/rm -rf $(NAME)
		@/bin/rm -f $(NAME_BONUS)
		@${MAKE} -C libft fclean

re: fclean all bonus

.PHONY: all bonus clean fclean re
