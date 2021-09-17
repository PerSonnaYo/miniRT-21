# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: latkins <latkins@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 18:13:07 by latkins           #+#    #+#              #
#    Updated: 2021/03/13 12:23:00 by latkins          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
HEAD = includes

SRCDIR	= srcs/

SRCS += mini.c
SRCS += get_line/get_next_line_bonus.c
SRCS += get_line/get_next_line_utils_bonus.c
SRCS += parcing/camcam.c
SRCS += parcing/color.c
SRCS += parcing/events.c
SRCS += parcing/figures.c
SRCS += parcing/freelist.c
SRCS += parcing/lights.c
SRCS += parcing/link_elem.c
SRCS += parcing/parcing.c
SRCS += parcing/parser_fun.c
SRCS += parcing/parser_fun1.c
SRCS += parcing/parser_fun2.c
SRCS += parcing/parser_fun3.c
SRCS += parcing/parser_fun4.c
SRCS += parcing/parsing_opr.c
SRCS += ray/rey.c
SRCS += ray/ray_fun1.c
SRCS += ray/ray_fun2.c
SRCS += ray/ray_fun.c 
SRCS += ray/keys.c 
SRCS += ray/inter_figu.c
SRCS += ray/bmp_s.c
SRCS += vector_fun/vector_gen1.c
SRCS += vector_fun/vector_gen.c
SRCS += vector_fun/vec_gen2.c
SRCS += vector_fun/color_fun1.c
SRCS += vector_fun/color_fun2.c
SRCS += vector_fun/color_fun.c
SRCS += ray/ray_fun3.c

CFILES = $(addprefix $(SRCDIR), $(SRCS))

OBJS = ${CFILES:.c=.o}

CC		= clang -g

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I $(HEAD)

LIB = ./libft

FLAGS = -L $(LIB) -lft

LIBFT 	= $(LIB)libft.a

MACOS_MACRO = -D MACOS

LINUX_MACRO = -D LINUX

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	MLX_DIR = ./minilibx_mms_20200219/
	MACOS_FLAGS	= -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	CFLAGS += $(MACOS_MACRO)
	FLAGS += $(MACOS_FLAGS)
endif
ifeq ($(UNAME),Linux)
	MLX_DIR = ./minilibx-linux-2120a379df774f47be595b2fa5233f203d4520cb/
	LINUX_FLAGS = -L $(MLX_DIR) -lmlx -lm -lX11 -lXext
	CFLAGS += $(LINUX_MACRO)
	FLAGS += $(LINUX_FLAGS)
endif

MMS = $(MLX_DIR)libmlx.dylib

all:	$(LIBFT) $(MMS) ${NAME}

${NAME}:	$(OBJS)
				@cp -f -v  $(MLX_DIR)libmlx.dylib ./
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o ${NAME}
$(LIBFT):
			@make -s -C $(LIB)

$(MMS):
			@make -s -C $(MLX_DIR)

clean:
			make clean -C $(LIB)
			make clean -C $(MLX_DIR)
			${RM} ${OBJS}
			${RM} libmlx.dylib

fclean:		clean
			make fclean -C $(LIB)
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re
