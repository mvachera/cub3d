NAME			= 	cub3D

SRCS_NAMES 		=	main.c extract.c check_map_content.c check_map.c put_in_struct.c utils.c ft_spliit.c \
					hook.c image.c move.c  partie_juju.c pixel.c set_map.c	utils_juju.c rotate.c \

LIBFT			=	libft.a

MLX				= 	libmlx.a

MLX_LINUX		= 	libmlx_Linux.a

DIR_SRCS		=	srcs

DIR_OBJS		=	objs

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

DEPS			=	${SRCS_NAMES:.c=.d}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

INC				=	-Iincludes -Ilibft -Imlx -Imlx_linux

LIB				=	-Llibft -lft -Lminilibx-linux

CC				=	cc

CDFLAGS 		= -MMD -MP

CFLAGS			=	-g3 -Wall -Werror -Wextra

MAKEFLAGS		=	--no-print-directory

MLX_FLAGS =	-lm -lmlx -lXext -lX11

all:	${NAME}

$(NAME): $(DIR_OBJS) $(OBJS)
	@ make -C libft
	@ $(CC) $(CFLAGS) $(OBJS) ${INC} minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a -L. -lXext -lX11 -lm $(LIB) -o $(NAME)
	@ echo "CUB3D"  | toilet -f future -F border --gay

$(OBJS) : $(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c
	@ $(CC) $(CFLAGS) $(CDFLAGS) $(INC) -c $< -o $@ 

$(DIR_OBJS):
	@ mkdir -p $(DIR_OBJS)
	@ mkdir -p objs/parsing
	@ mkdir -p objs/exec

clean:
	@ make clean -C libft
	@ rm -rf ${DIR_OBJS}

fclean:	clean
	@ make fclean -C libft
	@ rm -rf ${LIBFT}
	@ rm -rf ${NAME}


re:	fclean all

# -include $(DEPS)

.PHONY:	all clean fclean re 
