##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## minishell2
##

SRC	=	src/main.c	\
		src/cd.c	\
		src/base_command.c	\
		src/my_getenv.c		\
		src/my_setenv.c		\
		src/my_unsetenv.c	\
		src/check_builtin.c		\
		src/get_all_cmd.c		\
		src/redir.c		\
		src/cd_arg_handling.c \
		src/init_redir.c	\
		src/my_pipe.c

OBJ = $(SRC:.c=.o)

NAME	=	mysh

all: $(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		gcc -o $(NAME) $(OBJ) -Llib/my -lmy -W -Wall -Wextra -g

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)
	rm -f scr/*/*~
	rm -f *~

re: fclean all
