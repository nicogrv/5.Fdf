FILESLINUX =	ft_animation.c		ft_clean.c				ft_isdigit.c		ft_key_mouse2.c	ft_map2.c \
ft_map_print.c	get_next_line.c		ft_atoi.c				ft_color_calcul.c	ft_itoa.c			ft_line.c \
ft_map.c		ft_monitoring.c		get_next_line_utils.c	ft_calloc.c			ft_color_map.c		ft_key_mouse.c \
ft_line_color.c	ft_map_calcul.c		ft_start.c				ft_monitoring2.c	ft_only_linux.c

FILESMACOS =	ft_animation.c		ft_clean.c				ft_isdigit.c		ft_key_mouse2.c	ft_map2.c \
ft_map_print.c	get_next_line.c		ft_atoi.c				ft_color_calcul.c	ft_itoa.c			ft_line.c \
ft_map.c		ft_monitoring.c		get_next_line_utils.c	ft_calloc.c			ft_color_map.c		ft_key_mouse.c \
ft_line_color.c	ft_map_calcul.c		ft_start.c				ft_monitoring2.c	ft_only_macos.c

OBJSLINUX = ${FILESLINUX:.c=.o}
OBJSMACOS = ${FILESMACOS:.c=.o}
DEPS = ${FILES:.c=.d}
LIB = fdf
CC = gcc

INCLUDE = -I ./
FLAGS = -Wall -Werror -Wextra
FLAGSLINUX = -Wall -Werror -Wextra -lmlx -lm -lXext -MMD -lX11 -I ./lib/minilibx-linux -L ./lib/minilibx-linux
FLAGSMACOS = -lmlx -framework OpenGL -framework AppKit -MMD -I ./lib/minilibx_macos -L ./lib/minilibx_macos

%.o: %.c fdf.h
			${CC} -I. ${FLAGS} -MMD -c $< -o ${<:.c=.o}

linux: 	${OBJSLINUX}
		echo test
		+${MAKE} -C ./lib/minilibx-linux/
		${CC} -o ${LIB} ${OBJSLINUX} ${INCLUDE} ${FLAGSLINUX}

macos: 	${OBJSMACOS}
		echo oui
		+${MAKE} -C ./lib/minilibx_macos/
		${CC} -o ${LIB} ${OBJSMACOS} ${INCLUDE} ${FLAGSMACOS}

all:	linux

clean:	
		rm -f ${OBJSLINUX} ${DEPS} ${OBJSMACOS}
		rm -rf *.d
		+${MAKE} -C ./lib/minilibx_macos/ clean
		+${MAKE} -C ./lib/minilibx_macos/ clean

fclean:	clean;
		rm -f ${LIB}

re:	fclean all



-include ${DEPS}

.PHONY: all clean fclean re