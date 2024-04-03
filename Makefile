##
## EPITECH PROJECT, 2022
## my_teams
## File description:
## Makefile
##

all: lib server client

server:
	@ make -C src/server/ -s

client:
	@ make -C src/client/ -s

lib:
	@ make -C libs/my/ -s

clean:
	@ make clean -C src/server/ -s
	@ make clean -C src/client/ -s
	@ make clean -C libs/my/ -s

fclean:
	@ make fclean -C src/server/ -s
	@ make fclean -C src/client/ -s
	@ make fclean -C libs/my/ -s

re: fclean all

.PHONY: all server client clean fclean re
