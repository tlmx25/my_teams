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
VPATH += src/commands/create
VPATH += src/messages/
VPATH += src/request/
VPATH += src/team/
VPATH += src/team/link_team_user
VPATH += src/channel/
VPATH += src/thread/
VPATH += src/reply/

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
SRC += users_command.c
SRC += user_command.c
SRC += send_command.c
SRC += messages_command.c
SRC += logout_command.c
SRC += help_command.c
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
SRC += create_team.c
SRC += delete_team.c
SRC += add_team.c
SRC += remove_team.c
SRC += get_team.c
SRC += save_team.c
SRC += load_team.c
SRC += create_link.c
SRC += delete_link.c
SRC += add_link.c
SRC += remove_link.c
SRC += get_link.c
SRC += save_load_link.c
SRC += create_channel.c
SRC += delete_channel.c
SRC += add_channel.c
SRC += remove_channel.c
SRC += get_channel.c
SRC += save_channel.c
SRC += load_channel.c
SRC += create_thread.c
SRC += delete_thread.c
SRC += add_thread.c
SRC += remove_thread.c
SRC += get_thread.c
SRC += save_thread.c
SRC += load_thread.c
SRC += create_reply.c
SRC += delete_reply.c
SRC += add_reply.c
SRC += remove_reply.c
SRC += get_reply.c
SRC += save_reply.c
SRC += load_reply.c
SRC += use_command.c
SRC += create_command.c
SRC += create_team_command.c
SRC += create_channel_command.c
SRC += create_thread_command.c

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
