# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 20:17:33 by mvachera          #+#    #+#              #
#    Updated: 2023/12/06 19:03:33 by mvachera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3d

CC              = clang

CFLAGS  = -Wall -Wextra -Werror -g3

RM              = rm -f

PRINTF		= ft_printf

FT_PRINTF	= ft_printf/libftprintf.a

SRC     = srcs/main.c srcs/hook.c srcs/partie_juju.c srcs/utils_juju.c srcs/image.c srcs/pixel.c srcs/move.c srcs/set_map.c gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ	= ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${MAKE} -C ${PRINTF}
	${CC} ${OBJ} ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a -lX11 -lXext -L -lX11 -o ${NAME} ${FT_PRINTF}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
