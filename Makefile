SHELL = /bin/bash

FILESMACOS += ft_animation.c
FILESMACOS += ft_clean.c
FILESMACOS += ft_isdigit.c
FILESMACOS += ft_key_mouse2.c
FILESMACOS += ft_map2.c
FILESMACOS += ft_map_print.c
FILESMACOS += get_next_line.c
FILESMACOS += ft_atoi.c
FILESMACOS += ft_color_calcul.c
FILESMACOS += ft_itoa.c
FILESMACOS += ft_line.c
FILESMACOS += ft_map.c
FILESMACOS += ft_monitoring.c
FILESMACOS += ft_monitoring2.c
FILESMACOS += get_next_line_utils.c
FILESMACOS += ft_calloc.c
FILESMACOS += ft_color_map.c
FILESMACOS += ft_key_mouse.c
FILESMACOS += ft_line_color.c
FILESMACOS += ft_map_calcul.c
FILESMACOS += ft_start.c
FILESMACOS += ft_only_macos.c

FILESLINUX += ft_animation.c
FILESLINUX += ft_clean.c
FILESLINUX += ft_isdigit.c
FILESLINUX += ft_key_mouse2.c
FILESLINUX += ft_map2.c
FILESLINUX += ft_map_print.c
FILESLINUX += get_next_line.c
FILESLINUX += ft_atoi.c
FILESLINUX += ft_color_calcul.c
FILESLINUX += ft_itoa.c
FILESLINUX += ft_line.c
FILESLINUX += ft_map.c
FILESLINUX += ft_monitoring.c
FILESLINUX += ft_monitoring2.c
FILESLINUX += get_next_line_utils.c
FILESLINUX += ft_calloc.c
FILESLINUX += ft_color_map.c
FILESLINUX += ft_key_mouse.c
FILESLINUX += ft_line_color.c
FILESLINUX += ft_map_calcul.c
FILESLINUX += ft_start.c
FILESLINUX += ft_only_linux.c

NAME = Fdf
CC = cc

FLAGS = -Wall -Werror -Wextra -g
FLAGSLINUX = -Wall -Werror -Wextra -lmlx -lm -lXext -MMD -lX11 -I ./lib/minilibx-linux -L ./lib/minilibx-linux -D OS=0
FLAGSMACOS = -lmlx -framework OpenGL -framework AppKit -MMD -I ./lib/minilibx_macos -L ./lib/minilibx_macos 


OBJSLINUX = ${patsubst %.c, ${OBJS_PATH_LINUX}/%.o, ${FILESLINUX}}
OBJS_PATH_LINUX = ./_Objet_linux

OBJSMACOS = ${patsubst %.c, ${OBJS_PATH_MACOS}/%.o, ${FILESMACOS}}
OBJS_PATH_MACOS = ./_Objet_macos

vpath %.c ./

all:	
	@	echo "1.make asset"
	@	echo "2.make linux / make macos"

${OBJSLINUX}: ${OBJS_PATH_LINUX}/%.o: %.c Makefile fdf.h
	@	mkdir -p ${OBJS_PATH_LINUX}
	@	$(COLORCOMPILLINUX)
	@	${CC} -D OS=0 ${FLAGS} -c $< -o $@



${OBJSMACOS}: ${OBJS_PATH_MACOS}/%.o: %.c Makefile fdf.h
	@	mkdir -p ${OBJS_PATH_MACOS}
	@	$(COLORCOMPILMAC)
	@	${CC} -D OS=1 ${FLAGS} -c $< -o $@


asset:
	@	echo -ne "\r\033[2K" $(YELLOW) "\tDownload Lib/map..." "\033[0m"
	@	git clone https://github.com/nicogrv/5.5Fdf_Libs-Maps.git --depth 1 --quiet
	@	mv ./5.5Fdf_Libs-Maps/* . 
	@	rm -rf 5.5Fdf_Libs-Maps
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "\tDownload Lib/map OK" "\033[0m\n"

assetclean:
	@	rm -rf lib
	@	rm -rf maps

linux:  ${OBJSLINUX}
	@	$(MAKE) --no-print-directory -s -C ./lib/minilibx-linux/
	@	${CC} -o ${NAME} ${OBJSLINUX} ${INCLUDE} ${FLAGSLINUX}
	@	echo -ne "\r\033[2K" $(LIGHTCYAN) "./Fdf ./map/{...}" "\033[0m" "\n"
 	

macos: 	${OBJSMACOS}
	@	$(MAKE) --no-print-directory -s --silent --quiet -C lib/minilibx_macos
	@	${CC} -o ${NAME} ${OBJSMACOS} ${INCLUDE} ${FLAGSMACOS} 
	@	echo -ne "\r\033[2K" $(LIGHTCYAN) "./Fdf ./map/{...}" "\033[0m" "\n"


clean:	
	@	echo -ne "\r\033[2K" $(YELLOW) "Cleaning\n\n"$(NC)
	@	$(MAKE) --no-print-directory -s -C ./lib/minilibx-linux/ clean
	@	$(MAKE) --no-print-directory -s -C ./lib/minilibx_macos/ clean
	@	rm -rf ${OBJS_PATH_MACOS}
	@	rm -rf ${OBJS_PATH_LINUX}

fclean:	clean;
	@	rm -rf ${NAME}
	@	echo -ne "\r\033[2K" $(GREEN) "\t$(NAME) Remove\n"$(NC)"\n"

-include ${DEPS}

.PHONY: all clean fclean re

NC='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHTGRAY='\033[0;37m'

DARKGRAY='\033[1;30m'
LIGHTRED='\033[1;31m'
LIGHTGREEN='\033[1;32m'
LIGHTBLUE='\033[1;34m'
LIGHTPURPLE='\033[1;35m'
LIGHTCYAN='\033[1;36m'
YELLOW='\033[1;33m'
WHITE='\033[1;37m'


ifndef COLORCOMPILMAC
COLORCOMPILMAC = \
	if [ "$(shell test $P -lt 33; echo $$?)" = "0" ]; then \
    	echo -ne "\r\033[2K" $(LIGHTRED) "[$(P)%] "$(DARKGRAY) "Compiling Fdf" $(WHITE) "$<"; \
	else \
		if [ "$(shell test $P -lt 66; echo $$?)" = "0" ]; then \
    		echo -ne "\r\033[2K" $(YELLOW) "[$(P)%]" $(DARKGRAY) "Compiling Fdf" $(WHITE) "$<"; \
		else \
       		echo -ne "\r\033[2K" $(LIGHTGREEN) "[$(P)%]" $(DARKGRAY) "Compiling Fdf" $(WHITE) "$<"; \
		fi \
	fi
T := $(words $(FILESMACOS))
N := x
C = $(words $N)$(eval N := x $N)
P = `expr $C '*' 100 / $T / 5`
endif

ifndef COLORCOMPILLINUX
COLORCOMPILLINUX = \
	if [ "$(shell test $P -lt 33; echo $$?)" = "0" ]; then \
    	echo -ne "\r\033[2K" $(LIGHTRED) "[$(P)%] "$(DARKGRAY) "Compiling Fdf" $(WHITE) "$<"; \
	else \
		if [ "$(shell test $P -lt 66; echo $$?)" = "0" ]; then \
    		echo -ne "\r\033[2K" $(YELLOW) "[$(P)%]" $(DARKGRAY) "Compiling Fdf" $(WHITE) "$<"; \
		else \
       		echo -ne "\r\033[2K" $(LIGHTGREEN) "[$(P)%]" $(DARKGRAY) "Compiling Fdf" $(WHITE) "$<"; \
		fi \
	fi
T := $(words $(FILESLINUX))
N := x
C = $(words $N)$(eval N := x $N)
P = `expr $C '*' 100 / $T / 5`
endif

