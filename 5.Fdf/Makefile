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
FILESLINUX += get_next_line_utils.c
FILESLINUX += ft_calloc.c
FILESLINUX += ft_color_map.c
FILESLINUX += ft_key_mouse.c
FILESLINUX += ft_line_color.c
FILESLINUX += ft_map_calcul.c
FILESLINUX += ft_start.c
FILESLINUX += ft_only_linux.c

# OBJSLINUX = ${FILESLINUX:.c=.o}
# OBJSMACOS = ${FILESMACOS:.c=.o}



NAME = Fdf
CC = cc

FLAGS = -Wall -Werror -Wextra -g
FLAGSLINUX = -Wall -Werror -Wextra -lmlx -lm -lXext -MMD -lX11 -I ./lib/minilibx-linux -L ./lib/minilibx-linux -D OS=0
FLAGSMACOS = -lmlx -framework OpenGL -framework AppKit -MMD -I ./lib/minilibx_macos -L ./lib/minilibx_macos -D OS=1



OBJSLINUX = ${patsubst %.c, ${OBJS_PATH_LINUX}/%.o, ${FILESLINUX}}
OBJS_PATH_LINUX = ./_Objet_linux

OBJSMACOS = ${patsubst %.c, ${OBJS_PATH_MACOS}/%.o, ${FILESMACOS}}
OBJS_PATH_MACOS = ./_Objet_macos

all:	
	@	echo "make linux / make macos"

${OBJSLINUX}: ${OBJS_PATH_LINUX}/%.o: %.c Makefile fdf.h
	@	mkdir -p ${OBJS_PATH_LINUX}
	@	$(COLORCOMPILLINUX)
	@	${CC} ${FLAGS} -c $< -o $@ 


${OBJSMACOS}: ${OBJS_PATH_MACOS}/%.o: %.c Makefile fdf.h
	@	mkdir -p ${OBJS_PATH_MACOS}
	@	$(COLORCOMPILMAC)
	@	${CC} ${FLAGS} -c $< -o $@

vpath %.c ./

asset:
		git clone git@github.com:nicogrv/5.5Fdf_Libs-Maps.git --depth 1


linux:  ${OBJSLINUX}
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "\t$(NAME) OK" "\033[0m" "\n"
	@	$(MAKE) --no-print-directory -s -C ./lib/minilibx-linux/
		${CC} -o ${NAME} ${OBJSLINUX} ${INCLUDE} ${FLAGSLINUX}
# @	echo -ne "\r\033[2K" $(LIGHTGREEN) "\t$(NAME) OK" "\033[0m" "\n"

 	

macos: 	${OBJSMACOS}
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "\t$(NAME) OK" "\033[0m" "\n"
	@	echo -ne "\r\033[2K" $(YELLOW) "\tLib..." "\033[0m"
	@	$(MAKE) --no-print-directory -s --silent --quiet -C lib/minilibx_macos
# @	$(MAKE) --no-print-directory -s -C libft
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "\tLIB OK" "\033[0m" "\n"
	@	${CC} -o ${NAME} ${OBJSMACOS} ${INCLUDE} ${FLAGSMACOS}


clean:	
	@	echo -ne "\r\033[2K" $(YELLOW) "Cleaning\n\n"$(NC)
	@	rm -f ${OBJSLINUX} ${DEPS} ${OBJSMACOS}
	@	$(MAKE) --no-print-directory -s -C ./lib/minilibx_macos/ clean
	@	$(MAKE) --no-print-directory -s -C ./lib/minilibx_macos/ clean

fclean:	clean;
	@	echo -ne "\r\033[2K" $(GREEN) "\t$(NAME) Remove\n"$(NC)"\n"
	@	rm -f ${NAME}

-include ${DEPS}

.PHONY: all clean fclean re


# SHELL = /bin/bash

# SRCS += ft_atoi.c
# SRCS += ft_free.c
# SRCS += ft_init.c
# SRCS += ft_verifinput.c
# SRCS += main.c
# SRCS += philo.c
# SRCS += print.c
# SRCS += utiles.c


# SRC_PATH += ./Philo_src/



# OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${SRCS}}
# OBJS_PATH = ./Philo_src/_Objet


# HEAD_PATH += -I ./Philo_src/_Include


# NAME = philo
# CC = cc

# CFLAGS += -Wall -Werror -Wextra
# CFLAGS += -g



# vpath %.c ${SRC_PATH}
# vpath %.h ${HEAD_PATH}

# all: ${NAME}

# run: all
# # @	clear
# 	@	./${NAME}

# valgrind: all
# 	valgrind ./${NAME}


# ${OBJS}: ${OBJS_PATH}/%.o: %.c Makefile philo.h
# 	@	mkdir -p ${OBJS_PATH}
# 	@	$(COLORCOMPIL)
# 	@	${CC} ${CFLAGS} -c $< -o $@ ${HEAD_PATH}

# ${NAME}:  ${OBJS}
# 	@	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB} ${HEAD_PATH}
# 	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "\t$(NAME) OK" "\033[0m" "\n"


# clean:
# 	@	echo -ne "\r\033[2K" $(YELLOW) "Cleaning\n\n"$(NC)
# 	@	rm -rf ${OBJS_PATH}


# fclean: clean
# 	@	rm -f ${NAME}
# 	@	echo -ne "\r\033[2K" $(GREEN) "\t$(NAME) Remove\n"$(NC)"\n"




# re: fclean
# 	@	echo -ne "\r\033[2K" $(YELLOW) "Rebuilding..."$(NC)"\n""\n"
# 	@	$(MAKE) -s


# .PHONY: re clean fclean 

NOCOLOR='\033[0m'
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

