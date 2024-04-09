##
## EPITECH PROJECT, 2022
## lib
## File description:
## Makefile
##

MAKEFLAGS += -silent
CC = gcc

VPATH := ../common/
VPATH += src/
VPATH += src/client/
VPATH += src/server/
VPATH += src/commands/
VPATH += src/messages/
VPATH += src/request/

SRC := $(shell find ../common/ -name '*.c' -exec basename {} \;)
SRC += main.c
SRC += create_client.c
SRC += add_client.c
SRC += free_client.c
SRC += remove_client.c
SRC += get_client.c
SRC += server.c
SRC += create_server.c
SRC += delete_server.c
SRC += server_manager.c
SRC += command_manager.c
SRC += manage_requests.c
SRC += login_command.c
SRC += save_client.c
SRC += load_client.c
SRC += create_message.c
SRC += delete_message.c
SRC += add_message.c
SRC += get_message.c
SRC += save_message.c
SRC += load_message.c
SRC += send_notification.c
SRC += create_delete_context.c

CFLAGS := -Wall -Wextra -iquote ../../includes/ -iquote ../../libs/myteams
CFLAGS += -iquote includes/

LDFLAGS := -luuid -L ../../libs/ -lmy -L${CURDIR}/../../libs/myteams
LDFLAGS += -l:libmyteams.so -Wl,-rpath=${CURDIR}/../../libs/myteams

BUILD_DIR = build/

Project = Server
NAME = ../../myteams_server

DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ && \
	($(PRINT) "  $(GREEN)「✔」$(CYAN)  %b$(RESET)\n" $<) || \
	($(PRINT) "  $(RED)[XX]$(CYAN)  %b$(RESET)\n" $< ; exit 1)

OBJ = $(SRC:%.c=$(BUILD_DIR)%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@ $(PRINT) "$(YELLOW)%-40b$(RESET)" "Building $(NAME)"
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && \
    	(printf "$(GREEN)Done$(RESET)\n" ; exit 0) || \
    	(printf "$(RED)Fail$(RESET)\n" ; exit 1)

clean: tests_clean
	@ $(PRINT) "$(YELLOW)%-40b$(RESET)" "Clean files"
	rm -rf $(BUILD_DIR)
	rm -f $(OBJ)
	rm -f *~
	rm -f \#*\#
	rm -f vgcore.*
	@ printf "$(GREEN)Done$(RESET)\n"

fclean: clean tests_clean
	@ $(PRINT) "$(YELLOW)%-40b$(RESET)" "Clean $(NAME)"
	rm -f $(NAME)
	@ printf "$(GREEN)Done$(RESET)\n"

CFLAGSTEST += -lcriterion --coverage

tests_run:
	$(CC) -o unit_tests $(filter-out build/main.o, $(SRCT))\
 	tests/tests.cpp -I include/ $(LDFLAGS) $(CFLAGS) $(CFLAGSTEST)
	-./unit_tests

tests_clean:
	@ rm -f *.gcno
	@ rm -f *.gcda
	@ rm -f unit_tests


re: 	fclean all

.PHONY: all clean fclean re .SILENT

PRINT	=	printf "\033[0;36m$(Project) \033[0;34m▷ \033[0m" ; printf
RESET	=	\033[0m
RED	=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;35m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[1;36m
