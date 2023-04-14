FILES =			ft_animation.c		ft_clean.c				ft_isdigit.c		ft_key_mouse2.c	ft_map2.c \
ft_map_print.c	get_next_line.c		ft_atoi.c				ft_color_calcul.c	ft_itoa.c			ft_line.c \
ft_map.c		ft_monitoring.c		get_next_line_utils.c	ft_calloc.c			ft_color_map.c		ft_key_mouse.c \
ft_line_color.c	ft_map_calcul.c		ft_start.c				ft_monitoring2.c	ft_init_mlx.c

OBJS = ${FILES:.c=.o}
DEPS = ${FILES:.c=.d}
LIB = fdf
CC = gcc

INCLUDE = -I ./
FLAGSLINUX = -Wall -Werror -Wextra -lmlx -lm -lXext -MMD -lX11 -I ./lib/minilibx-linux -L ./lib/minilibx-linux
FLAGSMACOS = -lmlx -framework OpenGL -framework AppKit -I ./lib/minilibx_macos -L ./lib/minilibx_macos

%.o: %.c fdf.h
			${CC} -I. ${FLAGSLINUX} -MMD -c $< -o ${<:.c=.o}

linux: 	${OBJS}
		+${MAKE} -C ./lib/minilibx-linux/
		${CC} -o ${LIB} ${OBJS} ${INCLUDE} ${FLAGSLINUX}

macos: 	${OBJS}
		+${MAKE} -C ./lib/minilibx_macos/
		${CC} -o ${LIB} ${OBJS} ${INCLUDE} ${FLAGSMACOS}

all:	linux

clean:	
		rm -f ${OBJS} ${DEPS}
		+${MAKE} -C ./lib/minilibx_macos/ clean
		+${MAKE} -C ./lib/minilibx_macos/ clean

fclean:	clean;
		rm -f ${LIB}

re:	fclean all



-include ${DEPS}

.PHONY: all clean fclean re