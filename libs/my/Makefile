##
## EPITECH PROJECT, 2022
## make
## File description:
## make
##

MAKEFLAGS += -silent

SRC     =	concat_params.c	\
		my_compute_power_rec.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_showmem.c	\
		my_showstr.c	\
		my_show_word_array.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_str_to_word_array.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_nbletter.c	\
		my_dellign.c	\
		my_puterror.c	\
		my_addlign.c	\
		my_puttab.c	\
		my_arrsize.c	\
		my_putnbrm.c	\
		my_str_in_str.c	\
		my_calloc.c	\
		my_array_to_str.c	\
		my_clean_string.c	\
		my_count_char.c	\
		is_in_array.c

BUILD_DIR =	build/

DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif


$(BUILD_DIR)%.o: %.c
	@mkdir -p $(@D)
	#@echo "  CC       $<      $@"
	@$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:%.c=$(BUILD_DIR)%.o)

BLUE = \033[1;34m
NC = \033[0m

NAME    =	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../
	mkdir -p ../../includes
	cp my.h ../../includes

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f ../$(NAME)

re:	fclean all

.PHONY: all clean fclean re .SILENT
