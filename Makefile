# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 17:03:42 by sutku             #+#    #+#              #
#    Updated: 2023/03/14 21:29:49 by sutku            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

SL_SRC		=	so_long.c error.c put_image.c map_control.c create_data.c map_assets.c\
				directions.c put_image_two.c
SL_OBJ		=	$(SL_SRC:.c=.o)

BONUS_SRC	=	so_long_bonus/so_long.c so_long_bonus/error.c so_long_bonus/put_image.c\
				so_long_bonus/map_control.c so_long_bonus/create_data.c so_long_bonus/map_assets.c\
				so_long_bonus/directions.c so_long_bonus/put_image_two.c
BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

GNL_SRC		=	gnl/get_next_line_utils.c gnl/get_next_line.c
GNL_OBJ		=	$(GNL_SRC:.c=.o)

MLX			=	MLX42/build/
MLX_LIB		=	MLX42/build/libmlx42.a

LIBFT		=	libft/
LIBFT_LIB	=	libft/libft.a

PRINTF		=	ftprintf/
PRINTF_LIB	=	ftprintf/libftprintf.a

CC		= 	cc
RM		=   rm -f
CFLAGS	=	-Wall -Werror -Wextra -g # -fsanitize=address

NAME	=	so_long
NAME_B	=	sl_bonus

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;32m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all:	$(NAME)

$(NAME): $(SL_OBJ) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(SL_OBJ) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_OBJ) -o $(NAME)  -I MLX42/include -lglfw -L /Users/$(USER)/homebrew/opt/glfw/lib/
	echo "$(GREEN)so_long compiled successfully$(DEF_COLOR)"

$(NAME_B): $(BONUS_OBJ) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_OBJ) -o $(NAME_B) -I MLX42/include -lglfw -L /Users/$(USER)/homebrew/opt/glfw/lib/
	echo "$(GREEN)so_long_bonus compiled successfully$(DEF_COLOR)"

$(LIBFT_LIB):
	make bonus -C $(LIBFT) && make clean -C $(LIBFT)
	echo "$(GREEN)LIBFT compiled successfully$(DEF_COLOR)"

$(PRINTF_LIB):
	make -C $(PRINTF) && make clean -C $(PRINTF)
	echo "$(GREEN)Printf compiled successfully$(DEF_COLOR)"

$(MLX_LIB):
	make -C $(MLX)

clean:
	$(RM) $(SL_OBJ)
	$(RM) $(GNL_OBJ) $(BONUS_OBJ)
	$(RM) $(LIBFT_LIB) $(PRINTF_LIB)
	echo "$(MAGENTA)Object-Files are cleaned!$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)
	echo "$(MAGENTA)Programs / Libraries are cleaned!$(DEF_COLOR)"

bonus: $(NAME_B)

re: fclean all 

.PHONY: all clean fclean re