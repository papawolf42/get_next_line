# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 17:55:15 by gunkim            #+#    #+#              #
#    Updated: 2021/06/03 12:15:16 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	libgnl.a - Makefile
#	----------------------------------------
#	Refer to : https://github.com/google/honggfuzz/blob/master/Makefile
#	Refer to : https://github.com/JaeSeoKim/42cursus/blob/master/01_ft_printf/lib/libft/Makefile

# =========================
# what we want to make
# =========================

NAME    := libgnl.a

# =========================
# implicit rule
# =========================

CC      := gcc
CFLAGS  := -g
# CFLAGS    := -g3 -fsanitize=address
CFLAGS  += -Wall
CFLAGS  += -Wextra
CFLAGS  += -Werror

AR      := ar
ARFLAGS := -rcsu

RFLAGS  := rm -rf

# =========================
# source files
# =========================

SRCS := get_next_line.c \
		get_next_line_utils.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c

OBJS := $(SRCS:.c=.o)

# =========================
# dependency files
# =========================

DEPS := $(SRCS:.c=.d)

# =========================
# ANSI/VT100
# =========================

LF      := \n
CR      := \r
ESC     := \e

ER      := $(ESC)[1K
CRLF    := $(CR)$(LF)
ERCR    := $(ER)$(CR)

# =========================
# rules
# =========================

.PHONY : all clean fclean re

all : $(NAME)

clean : clean_depend
	@$(RFLAGS) $(OBJS)
	@printf "[$(NAME)] 🧹 Cleaned object files$(LF)"

fclean : clean
	@$(RFLAGS) $(NAME)
	@printf "[$(NAME)] 🧹 Cleaned library$(LF)"

re : fclean all

.PHONY: depend clean_depend

depend : $(DEPS)

clean_depend :
	@$(RFLAGS) depend_file
	@printf "[$(NAME)] 🧹 Cleaned dependency files$(LF)"

%.d : %.c
	@$(CC) -MM $< -I$(DIR_INC) -I$(DIR_LIBFT_INC) | sed 's|^|$(DIR_OBJ)/|' >> depend_file

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@printf "$(ERCR)[$(NAME)] ✔️  Compiled done\n"

%.o : %.c
	@$(CC) -g $(CFLAGS) -c $< -o $@
	@printf "$(ERCR)[$(NAME)] 🔧 Compiling object file $@"

