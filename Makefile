# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 17:03:42 by sutku             #+#    #+#              #
#    Updated: 2023/03/03 15:51:18 by sutku            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

SL_SRC		=	so_long.c error.c put_image.c map_control.c create_data.c map_assets.c movements.c directions.c
SL_OBJ		=	$(SL_SRC:.c=.o)

GNL_SRC		=	gnl/get_next_line_utils.c gnl/get_next_line.c
GNL_OBJ		=	$(GNL_SRC:.c=.o)

MLX			=	MLX42/build/
MLX_LIB		=	MLX42/build/libmlx42.a
# MAKE_MLX	=	cd ./MLX42/ && make

LIBFT		=	libft/
LIBFT_LIB	=	libft/libft.a

PRINTF		=	ftprintf/
PRINTF_LIB	=	ftprintf/libftprintf.a

CC		= 	cc
RM		=   rm -f
CFLAGS	=	-fsanitize=address
NAME	=	so_long

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
	$(CC) $(CFLAGS) $(SL_OBJ) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_OBJ) -o $(NAME) -lglfw -L /Users/$(USER)/homebrew/opt/glfw/lib/ -I ./MLX42/include
	echo "so_long compiled successfully"

$(LIBFT_LIB):
	make bonus -C $(LIBFT) && make clean -C $(LIBFT)
	echo "$(GREEN)LIBFT compiled successfully"

$(PRINTF_LIB):
	make -C $(PRINTF) && make clean -C $(PRINTF)
	echo "Printf compiled successfully"
$(MLX_LIB):
	make -C $(MLX)

clean:
	$(RM) $(SL_OBJ)
	$(RM) $(GNL_OBJ)
	$(RM) $(LIBFT_LIB) $(PRINTF_LIB)
	echo "$(MAGENTA)Object-Files are cleaned!"

fclean: clean
	$(RM) $(NAME)
	echo "$(MAGENTA)Programs / Libraries are cleaned!"
	
re: fclean all 

.PHONY: all clean fclean re