##
## EPITECH PROJECT, 2024
## nm_objdump
## File description:
## Makefile
##

CC 			= 	gcc
AR			=	ar rc

NAME		=	libmsecurity.a
FNAME		=	MonkeySecurity

SRC			:= my_sha1.c
SRC			+= sha1_tools.c
SRC			+= chiffrement_string.c

VPATH		:=	src/
VPATH		+=	src/hash/
VPATH		+=	src/chiffrement/

vpath %.c $(VPATH)

BUILD_DIR	=	build

OBJ			=	$(SRC:%.c=$(BUILD_DIR)/%.o)

IFLAGS		=	-I ./include/
CFLAGS		=	-Wall -Wextra $(IFLAGS)

TMP_FILES	=	*.gcno					\
    			*.gcda					\
    			vgcore.*				\
    			*.log					\
    			temp.txt				\
    			coding-style-reports.log\
    			-r $(BUILD_DIR)			\
    			$(OBJ)

# ------ DISPLAY -------- #
# \e[38;5;${i}m for 256 colors and \e[38;2;${r};${g};${b}m for 24 bits colors

ECHO 		= echo

C_RESET 	= \033[00m
C_BLACK 	= \e[30m
C_RED		= \e[31m
C_GREEN 	= \e[32m
C_YELLOW 	= \e[33m
C_BLUE		= \e[34m
C_PINK		= \e[35m
C_CYAN		= \e[36m
C_WHITE		= \e[37m
C_GREY		= \e[90m
C_FULL_BLACK= \e[40m
C_FULL_RED	= \e[41m
C_FULL_GREEN= \e[42m
C_FULL_YELLOW= \e[43m
C_FULL_BLUE	= \e[44m
C_FULL_PINK	= \e[45m
C_FULL_CYAN	= \e[46m
C_FULL_WHITE= \e[47m

C_BOLD		= \e[1m
C_UNDERLINE	= \e[4m

# ----------------------- #

all:		$(NAME)

%:
	@ $(ECHO) "$(C_RED)|==========> RULE NOT FOUND. <==========|$(C_RESET)"

%.c:
	@ $(ECHO) "$(C_RED)[$(FNAME)][KO] -> $@$(C_RESET)"
	@ exit 1

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	@ $(AR) $@ $^
	@ mv $(NAME) ../
	@ cp include/msecurity.h ../../includes

clean:
	@ $(RM) $(TMP_FILES)

fclean:		clean
	@ $(RM) ../$(NAME)

re:		fclean all

debug: CFLAGS += -g
debug: CFLAGS += -Werror
debug: re

.PHONY: all re clean fclean debug
