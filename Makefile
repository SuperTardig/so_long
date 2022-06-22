# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bperron <bperron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 10:16:37 by bperron           #+#    #+#              #
#    Updated: 2022/06/22 15:22:10 by bperron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wall -Wextra -g
RM = rm -rf

NAME = so_long
NAME_BONUS = so_long_bonus

LIBFT = @$(MAKE) -sC libft
LIB = ./libft/libft.a

HEADERS = include/so_long.h
SRCS = src/so_long.c src/init.c src/map.c src/map_utils.c src/map_utils2.c src/plane.c src/move.c src/hook.c src/enemy.c src/enemy_move.c
OBJS = $(SRCS:.c=.o)

LIBFT_BONUS = @$(MAKE) -sC bonus/libft
LIB_BONUS = ./bonus/libft/libft.a

HEADERS_BONUS = bonus/include/so_long_bonus.h
SRCS_BONUS = bonus/src/so_long_bonus.c bonus/src/init_bonus.c bonus/src/map_bonus.c bonus/src/map_utils_bonus.c bonus/src/map_utils2_bonus.c bonus/src/plane_bonus.c bonus/src/move_bonus.c bonus/src/hook_bonus.c bonus/src/enemy_bonus.c bonus/src/enemy_move_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
	echo "Mandatory compilation done"

$(NAME): $(SRCS) $(OBJS)
	$(LIBFT)
	$(CC) $(CFLAGS) $(LIB) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(LIBFT) clean
	$(LIBFT_BONUS) clean
	$(RM) $(OBJS) $(OBJS_BONUS)
	echo "Clean done"

fclean:	clean
	$(LIBFT) fclean
	$(LIBFT_BONUS) fclean
	$(RM) $(NAME) $(NAME_BONUS)
	echo "Fclean done"

bonus: $(NAME_BONUS)
	echo "Bonus compilation done"

$(NAME_BONUS): $(SRCS_BONUS) $(OBJS_BONUS) $(HEADERS_BONUS)
	$(LIBFT_BONUS)
	$(CC) $(CFLAGS) $(LIB_BONUS) $(OBJS_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

re:	fclean all

nolong:
	echo "	———————————No Long?–––———————————"
	echo "	⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝"
	echo "	⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇"
	echo "	⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀"
	echo "	 ⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀"
	echo "	⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀"
	echo "	⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀"
	echo "	⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀"
	echo "	⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀"
	echo "	⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	echo "	⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	echo "	⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	echo "	⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	echo "	⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	echo "	—————————————————————————————–––"

.PHONY: all clean fclean re noalgo nochecker

.SILENT: all $(NAME) $(NAME_BONUS) bonus clean fclean $(OBJS) $(OBJS_BONUS)  nolong
